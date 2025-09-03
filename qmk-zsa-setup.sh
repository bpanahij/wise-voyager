#!/bin/bash

# QMK Setup Script for ZSA keyboards (Moonlander/Voyager)
# Uses the ZSA fork of QMK firmware

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

DOTFILES_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
QMK_DIR="$HOME/qmk_firmware"  # Standard location for QMK

setup_qmk_dependencies() {
    echo -e "${BLUE}=== Installing QMK Dependencies ===${NC}"
    echo
    
    # Install system dependencies for Arch Linux
    if [ -f /etc/arch-release ]; then
        echo "Installing QMK dependencies via pacman..."
        
        # Core dependencies
        sudo pacman -S --needed --noconfirm \
            python \
            python-pip \
            python-pipx \
            python-setuptools \
            python-wheel \
            python-virtualenv \
            avr-gcc \
            avr-binutils \
            avr-libc \
            arm-none-eabi-gcc \
            arm-none-eabi-binutils \
            arm-none-eabi-newlib \
            dfu-programmer \
            dfu-util \
            avrdude \
            git \
            make \
            gcc \
            unzip \
            wget \
            zip
        
        # Python dependencies for QMK (to avoid pip issues)
        echo "Installing Python modules via pacman..."
        PYTHON_PACKAGES=(
            python-pyserial
            python-pyusb
            python-pillow
            python-pygments
            python-colorama
            python-hid
            python-appdirs
            python-argcomplete
            python-jsonschema
            python-milc
            python-dotty-dict
        )
        
        for package in "${PYTHON_PACKAGES[@]}"; do
            sudo pacman -S --needed --noconfirm "$package" 2>/dev/null || echo "  ! $package not available"
        done
    else
        echo -e "${YELLOW}Not on Arch Linux. Please install dependencies manually.${NC}"
        echo "Visit: https://docs.qmk.fm/#/newbs_getting_started"
    fi
    
    echo -e "${GREEN}✓ System dependencies installed${NC}"
    echo
    
    # Install QMK CLI via pipx with injected dependencies
    echo "Installing QMK CLI via pipx..."
    if ! command -v qmk &> /dev/null; then
        pipx install qmk
        echo -e "${GREEN}✓ QMK CLI installed via pipx${NC}"
        
        # Inject missing dependencies
        echo "Injecting additional dependencies..."
        pipx inject qmk appdirs argcomplete colorama dotty-dict hid jsonschema milc pygments pyserial pyusb pillow 2>/dev/null || true
    else
        echo -e "${GREEN}✓ QMK CLI already installed${NC}"
        echo "  Reinstalling QMK CLI to fix dependencies..."
        pipx uninstall qmk 2>/dev/null || true
        pipx install qmk
        pipx inject qmk appdirs argcomplete colorama dotty-dict hid jsonschema milc pygments pyserial pyusb pillow 2>/dev/null || true
    fi
    
    # Ensure pipx binaries are in PATH
    if [[ ":$PATH:" != *":$HOME/.local/bin:"* ]]; then
        echo
        echo -e "${YELLOW}Adding ~/.local/bin to PATH...${NC}"
        echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
        echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.zshrc 2>/dev/null || true
        export PATH="$HOME/.local/bin:$PATH"
        echo "  Added to shell configuration"
    fi
    
    echo
}

setup_zsa_qmk() {
    echo -e "${BLUE}=== Setting up ZSA QMK Firmware ===${NC}"
    echo
    
    # Check if directory already exists
    if [ -d "$QMK_DIR" ]; then
        echo -e "${YELLOW}QMK directory already exists at $QMK_DIR${NC}"
        echo "Would you like to:"
        echo "1. Remove and re-clone (recommended for clean setup)"
        echo "2. Update existing repository"
        echo "3. Skip repository setup"
        read -p "> " repo_choice
        
        case $repo_choice in
            1)
                echo "Backing up existing directory..."
                mv "$QMK_DIR" "${QMK_DIR}.backup.$(date +%Y%m%d_%H%M%S)"
                echo -e "${GREEN}✓ Backup created${NC}"
                ;;
            2)
                cd "$QMK_DIR"
                git fetch origin
                git pull
                echo -e "${GREEN}✓ Repository updated${NC}"
                echo
                return 0
                ;;
            3)
                echo "Skipping repository setup"
                echo
                return 0
                ;;
        esac
    fi
    
    # Clone ZSA's QMK fork with firmware25 branch
    echo "Cloning ZSA QMK firmware repository..."
    cd "$HOME"
    qmk setup zsa/qmk_firmware -b firmware25 -y
    
    echo -e "${GREEN}✓ ZSA QMK firmware repository set up${NC}"
    echo
}

setup_udev_rules() {
    echo -e "${BLUE}=== Setting up udev rules ===${NC}"
    
    if [ -f "$QMK_DIR/util/udev/50-qmk.rules" ]; then
        sudo cp "$QMK_DIR/util/udev/50-qmk.rules" /etc/udev/rules.d/
        sudo udevadm control --reload-rules
        sudo udevadm trigger
        echo -e "${GREEN}✓ Udev rules installed${NC}"
    else
        echo -e "${YELLOW}! Udev rules file not found, you may need to set them up manually${NC}"
    fi
    
    # Add user to required groups
    echo "Adding user to required groups..."
    sudo usermod -a -G uucp,lock $USER 2>/dev/null || true
    echo -e "${GREEN}✓ User added to uucp and lock groups${NC}"
    echo -e "${YELLOW}  Note: You may need to log out and back in for group changes to take effect${NC}"
    echo
}

setup_keyboard_keymaps() {
    echo -e "${BLUE}=== Setting up Keyboard Keymaps ===${NC}"
    echo
    
    KEYBOARDS_DIR="$DOTFILES_DIR/keyboards"
    mkdir -p "$KEYBOARDS_DIR"
    
    echo "This will set up your keyboard layouts as git submodules"
    echo "and create symlinks in the QMK firmware directory."
    echo
    
    # Setup Moonlander
    if [ ! -d "$KEYBOARDS_DIR/wise-moonlander" ]; then
        echo "Enter the git repository URL for wise-moonlander"
        echo "(e.g., https://github.com/yourusername/wise-moonlander.git)"
        echo "or press Enter to skip:"
        read -p "> " moonlander_repo
        if [ -n "$moonlander_repo" ]; then
            cd "$DOTFILES_DIR"
            git submodule add "$moonlander_repo" "keyboards/wise-moonlander"
            echo -e "${GREEN}✓ wise-moonlander added as submodule${NC}"
        fi
    else
        echo -e "${GREEN}✓ wise-moonlander already exists${NC}"
    fi
    
    # Setup Voyager
    if [ ! -d "$KEYBOARDS_DIR/wise-voyager" ]; then
        echo
        echo "Enter the git repository URL for wise-voyager"
        echo "(e.g., https://github.com/yourusername/wise-voyager.git)"
        echo "or press Enter to skip:"
        read -p "> " voyager_repo
        if [ -n "$voyager_repo" ]; then
            cd "$DOTFILES_DIR"
            git submodule add "$voyager_repo" "keyboards/zsa/voyager/keymaps/wise-voyager"
            echo -e "${GREEN}✓ wise-voyager added as submodule${NC}"
        fi
    else
        echo -e "${GREEN}✓ wise-voyager already exists${NC}"
    fi
    
    # Initialize submodules
    if [ -f "$DOTFILES_DIR/.gitmodules" ]; then
        echo
        echo "Initializing and updating submodules..."
        cd "$DOTFILES_DIR"
        git submodule init
        git submodule update
        echo -e "${GREEN}✓ Submodules initialized${NC}"
    fi
    
    # Create symlinks
    echo
    echo "Creating symlinks to QMK firmware directory..."
    
    if [ -d "$KEYBOARDS_DIR/wise-moonlander" ]; then
        MOONLANDER_LINK="$QMK_DIR/keyboards/zsa/moonlander/keymaps/wise-moonlander"
        mkdir -p "$(dirname "$MOONLANDER_LINK")"
        if [ -L "$MOONLANDER_LINK" ] || [ -d "$MOONLANDER_LINK" ]; then
            rm -rf "$MOONLANDER_LINK"
        fi
        ln -s "$KEYBOARDS_DIR/wise-moonlander" "$MOONLANDER_LINK"
        echo -e "${GREEN}✓ Moonlander symlink created${NC}"
    fi
    
    if [ -d "$KEYBOARDS_DIR/wise-voyager" ]; then
        VOYAGER_LINK="$QMK_DIR/keyboards/voyager/keymaps/wise-voyager"
        mkdir -p "$(dirname "$VOYAGER_LINK")"
        if [ -L "$VOYAGER_LINK" ] || [ -d "$VOYAGER_LINK" ]; then
            rm -rf "$VOYAGER_LINK"
        fi
        ln -s "$KEYBOARDS_DIR/wise-voyager" "$VOYAGER_LINK"
        echo -e "${GREEN}✓ Voyager symlink created${NC}"
    fi
    
    echo
}

test_qmk_installation() {
    echo -e "${BLUE}=== Testing QMK Installation ===${NC}"
    echo
    
    # Check QMK CLI
    if command -v qmk &> /dev/null; then
        echo -e "${GREEN}✓ QMK CLI found: $(qmk --version)${NC}"
    else
        echo -e "${RED}✗ QMK CLI not found in PATH${NC}"
        return 1
    fi
    
    # Run QMK doctor
    echo
    echo "Running QMK doctor to check environment..."
    cd "$QMK_DIR"
    qmk doctor
    
    echo
}

compile_test() {
    echo -e "${BLUE}=== Compilation Test ===${NC}"
    echo
    echo "Would you like to test compile your keymaps? (y/n)"
    read -p "> " test_compile
    
    if [[ "$test_compile" != [Yy]* ]]; then
        return 0
    fi
    
    cd "$QMK_DIR"
    
    echo
    echo "Which keyboard to compile?"
    echo "1. Moonlander (wise-moonlander)"
    echo "2. Voyager (wise-voyager)"
    echo "3. Both"
    echo "4. Skip"
    read -p "> " keyboard_choice
    
    case $keyboard_choice in
        1|3)
            echo
            echo "Compiling Moonlander firmware..."
            if qmk compile -kb moonlander -km wise-moonlander; then
                echo -e "${GREEN}✓ Moonlander firmware compiled${NC}"
            else
                echo -e "${RED}✗ Moonlander compilation failed${NC}"
            fi
            ;;&
        2|3)
            echo
            echo "Compiling Voyager firmware..."
            if qmk compile -kb voyager -km wise-voyager; then
                echo -e "${GREEN}✓ Voyager firmware compiled${NC}"
            else
                echo -e "${RED}✗ Voyager compilation failed${NC}"
            fi
            ;;
    esac
    
    echo
    echo "Firmware files (if successful):"
    ls -la "$QMK_DIR"/*.bin 2>/dev/null || echo "No firmware files found"
}

main() {
    echo -e "${BLUE}=====================================${NC}"
    echo -e "${BLUE}     ZSA QMK Setup Script${NC}"
    echo -e "${BLUE}=====================================${NC}"
    echo
    
    # Run setup steps
    setup_qmk_dependencies
    setup_zsa_qmk
    setup_udev_rules
    setup_keyboard_keymaps
    test_qmk_installation
    compile_test
    
    echo
    echo -e "${GREEN}=====================================${NC}"
    echo -e "${GREEN}     Setup Complete!${NC}"
    echo -e "${GREEN}=====================================${NC}"
    echo
    echo "Next steps:"
    echo "1. Log out and back in (for group permissions)"
    echo "2. Copy your keymap files if you haven't already:"
    echo "   cp -r /path/to/wise-moonlander/* $QMK_DIR/keyboards/moonlander/keymaps/wise-moonlander/"
    echo "3. Compile firmware:"
    echo "   cd $QMK_DIR && qmk compile -kb moonlander -km wise-moonlander"
    echo "4. Flash firmware:"
    echo "   cd $QMK_DIR && qmk flash -kb moonlander -km wise-moonlander"
    echo
    echo "Quick commands:"
    echo "  Compile: qmk compile -kb moonlander -km wise-moonlander"
    echo "  Flash:   qmk flash -kb moonlander -km wise-moonlander"
}

main "$@"

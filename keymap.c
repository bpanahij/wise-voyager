#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
    RGB_SLD = ML_SAFE_RANGE,
    ESC_COLON = SAFE_RANGE,
};

#define PLAY_PS KC_MEDIA_PLAY_PAUSE
#define VOL_UP KC_AUDIO_VOL_UP
#define VOL_DN KC_AUDIO_VOL_DOWN

#define PREV_TAB LCTL(LSFT(KC_TAB))
#define NXT_TAB LCTL(KC_TAB)
#define PRV_WIN LGUI(LSFT(KC_GRAVE))
#define NXT_WIN LGUI(KC_GRAVE)
#define MSN_CTL LALT(LCTL(KC_F3))
#define LFT_HLF LALT(LCTL(KC_LEFT))
#define RGT_HLF LALT(LCTL(KC_RIGHT))
#define FLL_SCR LALT(LCTL(KC_ENTER))
#define LFT_23 LALT(LCTL(KC_E))
#define CNTR LALT(LCTL(KC_C))
#define RGT_23 LALT(LCTL(KC_T))
#define L_THRD  LALT(LCTL(KC_D))
#define M_THRD LALT(LCTL(KC_F))
#define R_THRD LALT(LCTL(KC_G))

#define SCRN_SHT LGUI(LCTL(LSFT(KC_4)))
#define SCRN_SHT2 LGUI(LCTL(LSFT(KC_3)))

#define KEYMAPP LALT(LGUI(LCTL(LSFT(KC_K))))
#define DATAGRIP LALT(LGUI(LCTL(LSFT(KC_D))))
#define POSTMAN LALT(LGUI(LCTL(LSFT(KC_M))))
#define LINEAR LALT(LGUI(LCTL(LSFT(KC_L))))
#define WEBSTORM LALT(LGUI(LCTL(LSFT(KC_W))))
#define FINDER LALT(LGUI(LCTL(LSFT(KC_F))))
#define SPOTIFY LALT(LGUI(LCTL(LSFT(KC_G))))
#define TERMINAL LALT(LGUI(LCTL(LSFT(KC_T))))
#define ALACRITTY LALT(LGUI(LCTL(LSFT(KC_O))))
#define SLACK LALT(LGUI(LCTL(LSFT(KC_S))))
#define PYCHARM LALT(LGUI(LCTL(LSFT(KC_P))))
#define CHROME LALT(LGUI(LCTL(LSFT(KC_C))))

#define MOUSE_S LT(_MOUSE, KC_S)
#define TXT_T LT(_TXT_NAV, KC_T)
#define NP_N LT(_NUMPAD, KC_N)
#define CODE_P LT(_CODE_PUNC, KC_E)
#define FNC_I LT(_FUNC, KC_I)
#define APP_SP LT(_APP, KC_SPACE)
#define CTL_ENTR MT(MOD_LCTL,KC_ENTER)

enum voyager_layers {
    _COLEMAK,
    _CODE_PUNC,
    _NUMPAD,
    _TXT_NAV,
    _MOUSE,
    _APP,
    _FUNC
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_voyager(
        KC_ESCAPE,    KC_LBRC,   KC_LPRN,         KC_MINUS,   KC_RPRN,   KC_RBRC,        KC_LABK,         KC_SLASH,       KC_QUES,     KC_BSLS,         KC_SCLN,    KC_BSPC,
        KC_GRAVE,     KC_Q,      KC_W,            KC_F,       KC_P,      KC_G,           KC_J,            KC_L,           KC_U,        KC_Y,            KC_EQUAL,   ESC_COLON,
        KC_PLUS,      KC_A,      KC_R,            MOUSE_S,    TXT_T,     KC_D,           KC_H,            NP_N,           CODE_P,      FNC_I,           KC_O,       KC_QUOTE,
        KC_LEFT_ALT,  KC_Z,      KC_X,            KC_C,       KC_V,      KC_B,           KC_K,            KC_M,           KC_COMMA,    KC_DOT,          KC_SLASH,   KC_EXLM,
        APP_SP,       KC_LSFT,   KC_RIGHT_GUI,    CTL_ENTR
    ),
    [_CODE_PUNC]=LAYOUT_voyager(
        _______,      _______,   _______,         _______,    _______,   _______,        _______,         _______,        _______,     _______,         _______,    _______,
        _______,      KC_QUES,   KC_ASTR,         KC_HASH,    KC_PERC,   KC_PLUS,        _______,         _______,        _______,     _______,         _______,    _______,
        _______,      KC_AT,     KC_AMPR,         KC_DLR,     KC_TILD,   KC_MINUS,       KC_CIRC,         _______,        _______,     _______,         _______,    _______,
        _______,      _______,   _______,         KC_LABK,    KC_RABK,   _______,        _______,         _______,        _______,     _______,         _______,    _______,
        _______,      _______,   _______,         _______
    ),
    [_NUMPAD]=LAYOUT_voyager(
        _______,      _______,   _______,         _______,    _______,   _______,        _______,         _______,        KC_GRAVE,    _______,         _______,    _______,
        _______,      KC_ASTR,   KC_7,            KC_8,       KC_9,      KC_PLUS,        _______,         _______,        KC_CIRC,     KC_AMPR,         _______,    _______,
        _______,      KC_SLASH,  KC_4,            KC_5,       KC_6,      KC_MINUS,       _______,         _______,        KC_DLR,      KC_TILD,         KC_PIPE,    _______,
        _______,      KC_PERC,   KC_1,            KC_2,       KC_3,      KC_CALCULATOR,  _______,         KC_PERC,        _______,     _______,         _______,    _______,
        KC_0,         _______,   _______,         _______
    ),
    [_TXT_NAV]=LAYOUT_voyager(
        _______,      _______,   _______,         _______,    _______,   _______,        _______,         _______,        LGUI(KC_B),  _______,         _______,    _______,
        _______,      _______,   _______,         _______,    _______,   _______,        KC_PAGE_UP,      LSFT(KC_TAB),   KC_UP,       KC_TAB,          _______,    _______,
        _______,      _______,   _______,         _______,    _______,   _______,        KC_PGDN,         KC_LEFT,        KC_DOWN,     KC_RIGHT,        _______,    _______,
        _______,      _______,   _______,         _______,    _______,   _______,        LGUI(KC_C),      LGUI(KC_V),     KC_DOWN,     _______,         _______,    _______,
        _______,      _______,   _______,         _______
    ),
    [_MOUSE]=LAYOUT_voyager(
        _______,      _______,   _______,         _______,    _______,   _______,        KC_NO,           KC_MS_WH_LEFT,  KC_MS_BTN3,  KC_MS_WH_RIGHT,  KC_NO,      KC_NO,
        _______,      _______,   _______,         _______,    _______,   _______,        KC_MS_WH_UP,     KC_MS_BTN1,     KC_MS_UP,    KC_MS_BTN2,      KC_NO,      KC_NO,
        _______,      _______,   _______,         _______,    _______,   _______,        KC_MS_WH_DOWN,   KC_MS_LEFT,     KC_MS_DOWN,  KC_MS_RIGHT,     KC_NO,      KC_NO,
        _______,      _______,   _______,         _______,    _______,   _______,        KC_RIGHT_SHIFT,  LGUI(KC_LBRC),  KC_NO,       LGUI(KC_RBRC),   KC_NO,      KC_NO,
        _______,      _______,   KC_MS_BTN1,      KC_MS_BTN2
    ),
    [_APP]=LAYOUT_voyager(
        _______,      _______,   PREV_TAB,        _______,    NXT_TAB,   _______,        _______,         PRV_WIN,        MSN_CTL,     NXT_WIN,         _______,    _______,
        _______,      _______,   WEBSTORM,        FINDER,     PYCHARM,   SPOTIFY,        VOL_UP,          LFT_HLF,        FLL_SCR,     RGT_HLF,         _______,    _______,
        _______,      LINEAR,    POSTMAN,         SLACK,      TERMINAL,  DATAGRIP,       VOL_DN,          LFT_23,         CNTR,        RGT_23,          ALACRITTY,  _______,
        _______,      _______,   _______,         CHROME,     SCRN_SHT,  SCRN_SHT2,      KEYMAPP,         L_THRD,         M_THRD,      R_THRD,          _______,    _______,
        _______,      _______,   KC_PAUSE,        PLAY_PS
    ),
    [_FUNC]=LAYOUT_voyager(
        _______,      _______,   KC_F10,          KC_F11,     KC_F12,    _______,        _______,         _______,        _______,     _______,         _______,    _______,
        _______,      _______,   KC_F7,           KC_F8,      KC_F9,     _______,        _______,         _______,        _______,     _______,         _______,    _______,
        _______,      _______,   KC_F4,           KC_F5,      KC_F6,     _______,        _______,         _______,        _______,     _______,         _______,    _______,
        _______,      _______,   KC_F1,           KC_F2,      KC_F3,     _______,        _______,         _______,        _______,     _______,         _______,    _______,
        _______,      _______,   _______,         _______
    ),
};
const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_COLEMAK] = {
        {253,255,237}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {83,218,204},  {130,56,209}, {130,56,209}, {130,56,209}, {130,56,209}, {130,56,209},
        {83,218,204}, {130,56,209}, {130,56,209}, {219,255,255}, {219,255,255}, {130,56,209},
        {83,218,204}, {130,56,209}, {130,56,209}, {130,56,209}, {130,56,209}, {130,56,209},
        {219,255,255}, {83,218,204},

        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {253,255,237},
        {130,56,209}, {130,56,209}, {130,56,209}, {130,56,209}, {83,218,204}, {83,218,204},
        {130,56,209}, {219,255,255}, {219,255,255}, {219,255,255}, {130,56,209}, {83,218,204},
        {130,56,209}, {130,56,209}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {83,218,204}, {83,218,204}
    },
    [_CODE_PUNC] = {
        {0,0,0}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {0,0,0}, {0,0,0}, {0,0,0}, {83,218,204}, {83,218,204}, {0,0,0},
        {0,0,0}, {0,0,0},

        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {83,218,204}, {83,218,204},
        {83,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {83,218,204},
        {0,0,0}, {0,0,0}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {0,0,0}, {0,0,0}
    },
    [_NUMPAD] = {
        {253,255,237}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {83,218,204}, {83,218,204}, {219,255,255}, {219,255,255}, {219,255,255}, {83,218,204},
        {83,218,204}, {83,218,204}, {219,255,255}, {219,255,255}, {219,255,255}, {83,218,204},
        {130,56,209}, {83,218,204}, {219,255,255}, {219,255,255}, {219,255,255}, {189,255,238},
        {219,255,255}, {130,56,209},

        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {253,255,237},
        {130,56,209}, {130,56,209}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {130,56,209}, {130,56,209}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {130,56,209}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {130,56,209}, {130,56,209}
    },
    [_TXT_NAV] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0},

        {0,0,0}, {0,0,0}, {83,218,204}, {0,0,0}, {0,0,0}, {0,0,0},
        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {0,0,0}, {0,0,0},
        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {0,0,0}, {0,0,0},
        {83,218,204}, {83,218,204}, {83,218,204}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}
    },
    [_MOUSE] = {
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0},

        {0,0,0}, {189,255,238}, {177,238,221}, {189,255,238}, {0,0,0}, {0,0,0},
        {189,255,238}, {177,238,221}, {177,238,221}, {189,255,238}, {0,0,0}, {0,0,0},
        {189,255,238}, {177,238,221}, {177,238,221},  {177,238,221}, {0,0,0}, {0,0,0},
        {72,255,233}, {222,255,237}, {0,0,0}, {222,255,237}, {0,0,0}, {0,0,0},
        {83,218,204}, {72,255,233}
    },
    [_APP] = {
        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {83,218,204}, {83,218,204}, {189,255,238}, {189,255,238}, {189,255,238}, {189,255,238},
        {83,218,204}, {189,255,238}, {83,218,204}, {189,255,238}, {189,255,238}, {189,255,238},
        {83,218,204}, {83,218,204}, {83,218,204}, {189,255,238}, {83,218,204}, {189,255,238},
        {83,218,204}, {83,218,204},

        {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204}, {83,218,204},
        {83,218,204}, {189,255,238}, {189,255,238}, {189,255,238}, {83,218,204}, {83,218,204},
        {83,218,204}, {189,255,238}, {189,255,238}, {189,255,238}, {83,218,204}, {83,218,204},
        {83,218,204}, {189,255,238}, {189,255,238}, {189,255,238}, {83,218,204}, {83,218,204},
        {83,218,204}, {253,255,237}
    },
    [_FUNC] = {
        {0,0,0}, {0,0,0}, {130,255,239}, {130,255,239}, {130,255,239}, {0,0,0},
        {0,0,0}, {0,0,0}, {130,255,239}, {44,246,252}, {44,246,252}, {0,0,0},
        {0,0,0}, {0,0,0}, {130,255,239}, {130,255,239}, {130,255,239}, {0,0,0},
        {0,0,0}, {0,0,0}, {130,255,239}, {44,246,252}, {44,246,252}, {0,0,0},
        {0,0,0}, {0,0,0},

        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0},
        {0,0,0}, {0,0,0}
    },
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4,KC_S):
            return TAPPING_TERM + 50;
        case LT(3,KC_T):
            return TAPPING_TERM + 50;
        case LT(5,KC_SPACE):
            return TAPPING_TERM + 50;
        case LT(2,KC_N):
            return TAPPING_TERM + 50;
        case LT(1,KC_E):
            return TAPPING_TERM + 50;
        case LT(6,KC_I):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}





void set_layer_color(int layer) {
    for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
        HSV hsv = {
            .h = pgm_read_byte(&ledmap[layer][i][0]),
            .s = pgm_read_byte(&ledmap[layer][i][1]),
            .v = pgm_read_byte(&ledmap[layer][i][2]),
        };
        if (!hsv.h && !hsv.s && !hsv.v) {
            rgb_matrix_set_color( i, 0, 0, 0 );
        } else {
            RGB rgb = hsv_to_rgb( hsv );
            float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
        }
    }
}

bool rgb_matrix_indicators_user(void) {
    if (rawhid_state.rgb_control) {
        return false;
    }
    if (keyboard_config.disable_layer_led) { return false; }
    switch (biton32(layer_state)) {
        case _COLEMAK:
            set_layer_color(_COLEMAK);
            break;
        case _CODE_PUNC:
            set_layer_color(_CODE_PUNC);
            break;
        case _NUMPAD:
            set_layer_color(_NUMPAD);
            break;
        case _TXT_NAV:
            set_layer_color(_TXT_NAV);
            break;
        case _MOUSE:
            set_layer_color(_MOUSE);
            break;
        case _APP:
            set_layer_color(_APP);
            break;
        case _FUNC:
            set_layer_color(_FUNC);
            break;
        default:
            if (rgb_matrix_get_flags() == LED_FLAG_NONE)
                rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case ESC_COLON:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) ":");
            }
            break;
        case RGB_SLD:
            if (rawhid_state.rgb_control) {
                return false;
            }
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            return false;
    }
    return true;
}





const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_COLEMAK] = {
        {HSV_YELLOW}, {HSV_BLACK}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_RED},
        {HSV_BLACK},  {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_BLUE}, {HSV_CORAL}, {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE}, {HSV_CORAL},
        {HSV_BLUE}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_BLUE}, {HSV_BLUE},

        {HSV_RED}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_YELLOW},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_CORAL}, {HSV_BLUE},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE},
    },
    [_NUMPAD] = {
        {HSV_BLACK}, {HSV_BLACK}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_BLACK}, {HSV_CORAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_CORAL},
        {HSV_BLACK}, {HSV_CORAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_CORAL},
        {HSV_BLACK}, {HSV_CORAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_ORANGE},
        {HSV_BLACK}, {HSV_BLACK},

        {HSV_RED}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_BLACK},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}
    },
    [_TXT_NAV] = {
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK},

        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_BLUE}, {HSV_CORAL}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLUE}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}
    },
    [_MOUSE] = {
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK},

        {HSV_BLACK}, {HSV_ORANGE}, {HSV_PINK}, {HSV_ORANGE}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_ORANGE}, {HSV_PINK}, {HSV_PINK}, {HSV_ORANGE}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_ORANGE}, {HSV_PINK}, {HSV_PINK},  {HSV_PINK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_PURPLE}, {HSV_GOLD}, {HSV_BLACK}, {HSV_GOLD}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLUE}, {HSV_PURPLE}
    },
    [_APP] = {
        {HSV_BLACK}, {HSV_BLACK}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_RED},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
        {HSV_BLACK}, {HSV_ORANGE}, {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_ORANGE}, {HSV_CORAL}, {HSV_ORANGE},
        {HSV_BLACK}, {HSV_CORAL},

        {HSV_BLACK}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_CORAL}, {HSV_BLACK},
        {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_CORAL}, {HSV_AZURE}
    },
    [_FUNC] = {
        {HSV_BLACK}, {HSV_BLACK}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_GREEN}, {HSV_CORAL}, {HSV_CORAL}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_GREEN}, {HSV_CORAL}, {HSV_CORAL}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK},

        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}
    },
    [_KEYB] = {
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK},

        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK}, {HSV_BLACK},
        {HSV_BLACK}, {HSV_BLACK}
    }
};


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
        case _KEYB:
            set_layer_color(_KEYB);
            break;
        default:
            rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}



const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [_COLEMAK] = {
        {HSV_YELLOW}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE},  {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_BLUE}, {HSV_CORAL}, {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE}, {HSV_CORAL},
        {HSV_BLUE}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_BLUE}, {HSV_BLUE},

        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_YELLOW},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_CORAL}, {HSV_BLUE},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE},
    },
    [_CODE_PUNC] = {
        {HSV_OFF}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_CORAL}, {HSV_CORAL}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},

        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_CORAL},
        {HSV_OFF}, {HSV_OFF}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_OFF}, {HSV_OFF},
    },
    [_NUMPAD] = {
        {HSV_AZURE}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_CORAL},
        {HSV_OFF}, {HSV_CORAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_TEAL}, {HSV_ORANGE},
        {HSV_TEAL}, {HSV_OFF},

        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_AZURE},
        {HSV_OFF}, {HSV_OFF}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_OFF}, {HSV_OFF}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_OFF}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_OFF}, {HSV_OFF}
    },
    [_TXT_NAV] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_CORAL}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_OFF}, {HSV_OFF},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_OFF}, {HSV_OFF},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}
    },
    [_MOUSE] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},

        {HSV_OFF}, {HSV_ORANGE}, {HSV_PINK}, {HSV_ORANGE}, {HSV_OFF}, {HSV_OFF},
        {HSV_ORANGE}, {HSV_PINK}, {HSV_PINK}, {HSV_ORANGE}, {HSV_OFF}, {HSV_OFF},
        {HSV_ORANGE}, {HSV_PINK}, {HSV_PINK},  {HSV_PINK}, {HSV_OFF}, {HSV_OFF},
        {HSV_PURPLE}, {HSV_GOLD}, {HSV_OFF}, {HSV_GOLD}, {HSV_OFF}, {HSV_OFF},
        {HSV_BLUE}, {HSV_PURPLE}
    },
    [_APP] = {
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
        {HSV_CORAL}, {HSV_ORANGE}, {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE},
        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_ORANGE}, {HSV_CORAL}, {HSV_ORANGE},
        {HSV_CORAL}, {HSV_CORAL},

        {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_ORANGE}, {HSV_CORAL}, {HSV_CORAL},
        {HSV_CORAL}, {HSV_AZURE}
    },
    [_FUNC] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_GREEN}, {HSV_CORAL}, {HSV_CORAL}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_GREEN}, {HSV_CORAL}, {HSV_CORAL}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}
    },
    [_KEYB] = {
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF},

        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF}, {HSV_OFF},
        {HSV_OFF}, {HSV_OFF}
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
        case _KEYB:
            set_layer_color(_KEYB);
            break;
        default:
            rgb_matrix_set_color_all(0, 0, 0);
            break;
    }
    return true;
}


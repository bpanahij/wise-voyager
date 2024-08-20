
#define MOON_LED_LEVEL LED_LEVEL
#define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS

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
#define PRV_APP LSFT(KC_TAB)
#define NXT_APP KC_TAB
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
#define NC_SPACE LT(_NUMPAD, KC_SPACE)

#define FNC_MINUS LT(_FUNC, KC_MINUS)
#define APP_E LT(_APP, KC_E)
#define CTL_ENTR MT(MOD_LCTL, KC_ENTER)
#define KEYB_BSPC LT(_KEYB, KC_BSPC)

enum voyager_layers {
    _COLEMAK=0,
    _NUMPAD,
    _TXT_NAV,
    _MOUSE,
    _APP,
    _FUNC,
    _KEYB,
};


enum {
    GUI_APP,
    ESC_I,
};

typedef struct {
    bool is_press_action;
    int state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD = 2,
    DOUBLE_SINGLE_TAP = 3,
    DOUBLE_HOLD = 4,
};

static tap ql_tap_state = {
    .is_press_action = true,
    .state = 0
};

int cur_dance (tap_dance_state_t *state);
void gui_app_finished(tap_dance_state_t *state, void *user_data);
void gui_app_reset(tap_dance_state_t *state, void *user_data);

int cur_dance(tap_dance_state_t *state) {
    if(state->count == 1) {
        if (state->interrupted || !state->pressed) {
            return SINGLE_TAP ;
        }
        else {
            return SINGLE_HOLD;
        }
    }
    if(state->count == 2) {
        if (state->interrupted || !state->pressed) {
            return DOUBLE_SINGLE_TAP ;
        }
        else {
            return DOUBLE_HOLD;
        }
    }
    else {
        return 3;
    }
}

// ================================================
// ================================================
// GUI_APP key

void gui_app_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch(ql_tap_state.state) {
        case SINGLE_TAP:
            register_mods(MOD_BIT(KC_LSFT));
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_LSFT));
            break;
        case DOUBLE_SINGLE_TAP:
            tap_code16(KC_LPRN);
            break;
        case DOUBLE_HOLD:
            layer_on(_APP);
            break;
    }
}

void gui_app_reset(tap_dance_state_t *state, void *user_data) {
    switch(ql_tap_state.state) {
        case SINGLE_TAP:
            unregister_mods(MOD_BIT(KC_LSFT));
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_LSFT));
            break;
        case DOUBLE_SINGLE_TAP:
            break;
        case DOUBLE_HOLD:
            layer_off(_APP);
            break;
    }
    ql_tap_state.state = 0;
}
// ================================================
//

tap_dance_action_t tap_dance_actions[] = {
    [GUI_APP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, gui_app_finished, gui_app_reset)
};

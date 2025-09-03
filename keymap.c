#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

#include "wise_voyager.h"

extern bool set_scrolling;
extern bool navigator_turbo;
extern bool navigator_aim;

enum custom_keycodes {
    ESC_COLON = SAFE_RANGE,
    HSV_0_255_255,
    HSV_74_255_255,
    HSV_169_255_255,
    DRAG_SCROLL,
    TOGGLE_SCROLL,
    NAVIGATOR_INC_CPI,
    NAVIGATOR_DEC_CPI,
    NAVIGATOR_TURBO,
    NAVIGATOR_AIM
};


#define DUAL_FUNC_0 LT(12, KC_F14)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_voyager(
//    ┌──────────┬────┬───┬───────────┬───────┬─────┐                 ┌──────────┬───┬───┬───┬───┬──────┐
//    │   esc    │ no │ _ │ FNC_MINUS │  no   │ no  │                 │    no    │ ` │ / │ \ │ % │ bspc │
//    ├──────────┼────┼───┼───────────┼───────┼─────┤                 ├──────────┼───┼───┼───┼───┼──────┤
//    │    no    │ q  │ w │     f     │   p   │  g  │                 │    j     │ l │ u │ y │ = │  :   │
//    ├──────────┼────┼───┼───────────┼───────┼─────┤                 ├──────────┼───┼───┼───┼───┼──────┤
//    │   lctl   │ a  │ r │  MOUSE_S  │ TXT_T │  d  │                 │    h     │ n │ e │ i │ o │  '   │
//    ├──────────┼────┼───┼───────────┼───────┼─────┤                 ├──────────┼───┼───┼───┼───┼──────┤
//    │ left_ALT │ z  │ x │     c     │   v   │  b  │                 │    k     │ m │ , │ . │ / │  !   │
//    └──────────┴────┴───┴───────────┴───────┼─────┼──────┐   ┌──────┼──────────┼───┴───┴───┴───┴──────┘
//                                            │ spc │ lsft │   │ lgui │ CTL_ENTR │
//                                            └─────┴──────┘   └──────┴──────────┘
  KC_ESCAPE   , KC_NO , KC_UNDS , FNC_MINUS , KC_NO , KC_NO    ,                         KC_NO    , KC_GRAVE , KC_SLASH , KC_BSLS , KC_PERC  , KC_BSPC ,
  KC_NO       , KC_Q  , KC_W    , KC_F      , KC_P  , KC_G     ,                         KC_J     , KC_L     , KC_U     , KC_Y    , KC_EQUAL , KC_COLN ,
  KC_LCTL     , KC_A  , KC_R    , MOUSE_S   , TXT_T , KC_D     ,                         KC_H     , KC_N     , KC_E     , KC_I    , KC_O     , KC_QUOTE,
  KC_LEFT_ALT , KC_Z  , KC_X    , KC_C      , KC_V  , KC_B     ,                         KC_K     , KC_M     , KC_COMMA , KC_DOT  , KC_SLASH , KC_EXLM ,
                                                      KC_SPACE , KC_LSFT ,     KC_LGUI , CTL_ENTR
),

[_NUMPAD] = LAYOUT_voyager(
//    ┌─────┬─────┬───┬───┬───┬──────┐               ┌─────┬───┬─────┬─────┬─────┬─────┐
//    │     │     │ ( │ 0 │ ) │  *   │               │ no  │ ` │  /  │  \  │  %  │     │
//    ├─────┼─────┼───┼───┼───┼──────┤               ├─────┼───┼─────┼─────┼─────┼─────┤
//    │     │ no  │ 7 │ 8 │ 9 │  +   │               │  @  │ & │  [  │  ]  │  =  │  ;  │
//    ├─────┼─────┼───┼───┼───┼──────┤               ├─────┼───┼─────┼─────┼─────┼─────┤
//    │     │ no  │ 4 │ 5 │ 6 │  -   │               │  $  │ # │  (  │  )  │  ~  │  '  │
//    ├─────┼─────┼───┼───┼───┼──────┤               ├─────┼───┼─────┼─────┼─────┼─────┤
//    │     │ no  │ 1 │ 2 │ 3 │ calc │               │  ^  │ _ │     │     │     │     │
//    └─────┴─────┴───┴───┴───┼──────┼─────┐   ┌─────┼─────┼───┴─────┴─────┴─────┴─────┘
//                            │      │     │   │     │     │
//                            └──────┴─────┘   └─────┴─────┘
  _______ , _______ , KC_LPRN , KC_0 , KC_RPRN , KC_ASTR       ,                         KC_NO   , KC_GRAVE , KC_SLASH , KC_BSLS , KC_PERC  , _______ ,
  _______ , KC_NO   , KC_7    , KC_8 , KC_9    , KC_PLUS       ,                         KC_AT   , KC_AMPR  , KC_LBRC  , KC_RBRC , KC_EQUAL , KC_SCLN ,
  _______ , KC_NO   , KC_4    , KC_5 , KC_6    , KC_MINUS      ,                         KC_DLR  , KC_HASH  , KC_LPRN  , KC_RPRN , KC_TILD  , KC_QUOTE,
  _______ , KC_NO   , KC_1    , KC_2 , KC_3    , KC_CALCULATOR ,                         KC_CIRC , KC_UNDS  , _______  , _______ , _______  , _______ ,
                                                 _______       , _______ ,     _______ , _______
),

[_TXT_NAV] = LAYOUT_voyager(
//    ┌────┬────┬────┬────┬────┬────┐             ┌─────────┬───────────┬────────────────┬─────────────┬────┬────┐
//    │ no │ no │ no │ no │ no │ no │             │   no    │ www_back  │ www_favourites │ www_forward │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼────────────────┼─────────────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ pAGE_UP │ LSFT(tab) │       up       │     tab     │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼────────────────┼─────────────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │  pgdn   │   left    │      down      │    rght     │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼────────────────┼─────────────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │   no    │    no     │      down      │     no      │ no │ no │
//    └────┴────┴────┴────┴────┼────┼────┐   ┌────┼─────────┼───────────┴────────────────┴─────────────┴────┴────┘
//                             │ no │ no │   │ no │   no    │
//                             └────┴────┘   └────┴─────────┘
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO      , KC_WWW_BACK  , KC_WWW_FAVORITES , KC_WWW_FORWARD , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_PAGE_UP , LSFT(KC_TAB) , KC_UP            , KC_TAB         , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_PGDN    , KC_LEFT      , KC_DOWN          , KC_RIGHT       , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO      , KC_NO        , KC_DOWN          , KC_NO          , KC_NO , KC_NO,
                                          KC_NO , KC_NO ,     KC_NO , KC_NO
),

[_MOUSE] = LAYOUT_voyager(
//    ┌────┬────┬────┬────┬────┬────┐               ┌────────────┬─────────┬──────┬─────────┬────┬────┐
//    │ no │ no │ no │ no │ no │ no │               │     no     │  wh_l   │ btn3 │  wh_r   │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤               ├────────────┼─────────┼──────┼─────────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │               │    wh_u    │  btn1   │ ms_u │  btn2   │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤               ├────────────┼─────────┼──────┼─────────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │               │    wh_d    │  ms_l   │ ms_d │  ms_r   │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤               ├────────────┼─────────┼──────┼─────────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │               │ rght_SHIFT │ LGUI([) │  no  │ LGUI(]) │ no │ no │
//    └────┴────┴────┴────┴────┼────┼────┐   ┌──────┼────────────┼─────────┴──────┴─────────┴────┴────┘
//                             │ no │ no │   │ btn1 │    btn2    │
//                             └────┴────┘   └──────┴────────────┘
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                          KC_NO          , KC_MS_WH_LEFT , KC_MS_BTN3 , KC_MS_WH_RIGHT , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                          KC_MS_WH_UP    , KC_MS_BTN1    , KC_MS_UP   , KC_MS_BTN2     , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                          KC_MS_WH_DOWN  , KC_MS_LEFT    , KC_MS_DOWN , KC_MS_RIGHT    , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                          KC_RIGHT_SHIFT , LGUI(KC_LBRC) , KC_NO      , LGUI(KC_RBRC)  , KC_NO , KC_NO,
                                          KC_NO , KC_NO ,     KC_MS_BTN1 , KC_MS_BTN2
),

[_APP] = LAYOUT_voyager(
//    ┌────┬────┬─────────┬─────────┬─────────┬────┐                 ┌─────────┬──────────┬─────────┬─────────┬────┬────┐
//    │ no │ no │   no    │ LALT(0) │   no    │ no │                 │   no    │ PREV_TAB │ LALT(q) │ NXT_TAB │ no │ no │
//    ├────┼────┼─────────┼─────────┼─────────┼────┤                 ├─────────┼──────────┼─────────┼─────────┼────┼────┤
//    │ no │ no │ LALT(7) │ LALT(8) │ LALT(9) │ no │                 │ VOL_UP  │    no    │  C(w)   │   no    │ no │ no │
//    ├────┼────┼─────────┼─────────┼─────────┼────┤                 ├─────────┼──────────┼─────────┼─────────┼────┼────┤
//    │ no │ no │ LALT(4) │ LALT(5) │ LALT(6) │ no │                 │ VOL_DN  │    no    │    e    │    i    │ no │ no │
//    ├────┼────┼─────────┼─────────┼─────────┼────┤                 ├─────────┼──────────┼─────────┼─────────┼────┼────┤
//    │ no │ no │ LALT(1) │ LALT(2) │ LALT(3) │ no │                 │   no    │    no    │   no    │   no    │ no │ no │
//    └────┴────┴─────────┴─────────┴─────────┼────┼──────┐   ┌──────┼─────────┼──────────┴─────────┴─────────┴────┴────┘
//                                            │ no │ lsft │   │ lgui │ PLAY_PS │
//                                            └────┴──────┘   └──────┴─────────┘
  KC_NO , KC_NO , KC_NO      , LALT(KC_0) , KC_NO      , KC_NO ,                         KC_NO   , PREV_TAB , LALT(KC_Q) , NXT_TAB , KC_NO , KC_NO,
  KC_NO , KC_NO , LALT(KC_7) , LALT(KC_8) , LALT(KC_9) , KC_NO ,                         VOL_UP  , KC_NO    , C(KC_W)    , KC_NO   , KC_NO , KC_NO,
  KC_NO , KC_NO , LALT(KC_4) , LALT(KC_5) , LALT(KC_6) , KC_NO ,                         VOL_DN  , KC_NO    , KC_E       , KC_I    , KC_NO , KC_NO,
  KC_NO , KC_NO , LALT(KC_1) , LALT(KC_2) , LALT(KC_3) , KC_NO ,                         KC_NO   , KC_NO    , KC_NO      , KC_NO   , KC_NO , KC_NO,
                                                         KC_NO , KC_LSFT ,     KC_LGUI , PLAY_PS
),

[_FUNC] = LAYOUT_voyager(
//    ┌────┬────┬─────┬─────┬─────┬────┐             ┌────┬────┬────┬────┬────┬────┐
//    │ no │ no │ f10 │ f11 │ f12 │ no │             │ no │ no │ no │ no │ no │ no │
//    ├────┼────┼─────┼─────┼─────┼────┤             ├────┼────┼────┼────┼────┼────┤
//    │ no │ no │ f7  │ f8  │ f9  │ no │             │ no │ no │ no │ no │ no │ no │
//    ├────┼────┼─────┼─────┼─────┼────┤             ├────┼────┼────┼────┼────┼────┤
//    │ no │ no │ f4  │ f5  │ f6  │ no │             │ no │ no │ no │ no │ no │ no │
//    ├────┼────┼─────┼─────┼─────┼────┤             ├────┼────┼────┼────┼────┼────┤
//    │ no │ no │ f1  │ f2  │ f3  │ no │             │ no │ no │ no │ no │ no │ no │
//    └────┴────┴─────┴─────┴─────┼────┼────┐   ┌────┼────┼────┴────┴────┴────┴────┘
//                                │ no │ no │   │ no │ no │
//                                └────┴────┘   └────┴────┘
  KC_NO , KC_NO , KC_F10 , KC_F11 , KC_F12 , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_F7  , KC_F8  , KC_F9  , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_F4  , KC_F5  , KC_F6  , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_F1  , KC_F2  , KC_F3  , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
                                             KC_NO , KC_NO ,     KC_NO , KC_NO
),

[_KEYB] = LAYOUT_voyager(
//    ┌────┬────┬────┬────┬────┬────┐             ┌──────┬────┬────┬────┬────┬────┐
//    │ no │ no │ no │ no │ no │ no │             │  no  │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├──────┼────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ bRIU │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├──────┼────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ bRID │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├──────┼────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │  no  │ no │ no │ no │ no │ no │
//    └────┴────┴────┴────┴────┼────┼────┐   ┌────┼──────┼────┴────┴────┴────┴────┘
//                             │ no │ no │   │ no │  no  │
//                             └────┴────┘   └────┴──────┘
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_BRIU , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_BRID , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO   , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
                                          KC_NO , KC_NO ,     KC_NO , KC_NO
)
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOUSE_S:
            return TAPPING_TERM + 50;
        case TXT_T:
            return TAPPING_TERM + 50;
        case NC_SPACE:
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}

//extern rgb_config_t rgb_matrix_config;
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_COLON:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_ESC) ":");
            }
            return false;
            break;
        case DRAG_SCROLL:
          if (record->event.pressed) {
            set_scrolling = true;
          } else {
            set_scrolling = false;
          }
          return false;
        case TOGGLE_SCROLL:
          if (record->event.pressed) {
            set_scrolling = !set_scrolling;
          }
          return false;
        break;
        case NAVIGATOR_TURBO:
          if (record->event.pressed) {
            navigator_turbo = true;
          } else {
            navigator_turbo = false;
          }
          return false;
        case NAVIGATOR_AIM:
          if (record->event.pressed) {
            navigator_aim = true;
          } else {
            navigator_aim = false;
          }
          return false;
        case NAVIGATOR_INC_CPI:
          if (record->event.pressed) {
              pointing_device_set_cpi(1);
          }
          return false;
        case NAVIGATOR_DEC_CPI:
          if (record->event.pressed) {
              pointing_device_set_cpi(0);
          }
          return false;
        case HSV_0_255_255:
          if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(0,255,255);
          }
          return false;
        case HSV_74_255_255:
          if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(74,255,255);
          }
          return false;
        case HSV_169_255_255:
          if (record->event.pressed) {
            rgblight_mode(1);
            rgblight_sethsv(169,255,255);
          }
          return false;
    }
    return true;
}


const uint16_t PROGMEM punctuation_combo[] = {MOUSE_S, TXT_T, COMBO_END};
const uint16_t PROGMEM app_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM leave_app_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM num_layer[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM func_layer[] = {KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM keyb_layer[] = {KC_F, KC_P, COMBO_END};

combo_t key_combos[] = {
    COMBO(punctuation_combo, MO(_NUMPAD)),
    COMBO(app_combo, TG(_APP)),
    COMBO(leave_app_combo, TG(_APP)),
    COMBO(num_layer, MO(_NUMPAD)),
    COMBO(func_layer, MO(_FUNC)),
    COMBO(keyb_layer, MO(_KEYB)),
};



void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
bool is_mouse_record_kb(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case NAVIGATOR_INC_CPI ... NAVIGATOR_AIM:
    case DRAG_SCROLL:
    case TOGGLE_SCROLL:
      return true;
  }
  return is_mouse_record_user(keycode, record);
}



#include "led_map.c"

#include QMK_KEYBOARD_H
#include "version.h"
#include "wise_voyager.h"
#include "led_map.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────────┬───┬───┬─────────┬───────┬────────┐                     ┌──────────┬──────┬────────┬───────┬───┬───────────┐
//    │   esc    │ [ │ ( │    -    │   )   │   ]    │                     │    <     │  /   │   ?    │   \   │ ; │ KEYB_BSPC │
//    ├──────────┼───┼───┼─────────┼───────┼────────┤                     ├──────────┼──────┼────────┼───────┼───┼───────────┤
//    │    `     │ q │ w │    f    │   p   │   g    │                     │    j     │  l   │   u    │   y   │ = │ ESC_COLON │
//    ├──────────┼───┼───┼─────────┼───────┼────────┤                     ├──────────┼──────┼────────┼───────┼───┼───────────┤
//    │    +     │ a │ r │ MOUSE_S │ TXT_T │   d    │                     │    h     │ NP_N │ CODE_P │ FNC_I │ o │     '     │
//    ├──────────┼───┼───┼─────────┼───────┼────────┤                     ├──────────┼──────┼────────┼───────┼───┼───────────┤
//    │ left_ALT │ z │ x │    c    │   v   │   b    │                     │    k     │  m   │   ,    │   .   │ / │     !     │
//    └──────────┴───┴───┴─────────┴───────┼────────┼──────┐   ┌──────────┼──────────┼──────┴────────┴───────┴───┴───────────┘
//                                         │ APP_SP │ lsft │   │ rght_GUI │ CTL_ENTR │
//                                         └────────┴──────┘   └──────────┴──────────┘
[_COLEMAK] = LAYOUT_voyager(
  KC_ESCAPE   , KC_LBRC , KC_LPRN , KC_MINUS , KC_RPRN , KC_RBRC ,                              KC_LABK  , KC_SLASH , KC_QUES  , KC_BSLS , KC_SCLN  , KEYB_BSPC,
  KC_GRAVE    , KC_Q    , KC_W    , KC_F     , KC_P    , KC_G    ,                              KC_J     , KC_L     , KC_U     , KC_Y    , KC_EQUAL , ESC_COLON,
  KC_PLUS     , KC_A    , KC_R    , MOUSE_S  , TXT_T   , KC_D    ,                              KC_H     , NP_N     , CODE_P   , FNC_I   , KC_O     , KC_QUOTE ,
  KC_LEFT_ALT , KC_Z    , KC_X    , KC_C     , KC_V    , KC_B    ,                              KC_K     , KC_M     , KC_COMMA , KC_DOT  , KC_SLASH , KC_EXLM  ,
                                                         APP_SP  , KC_LSFT ,     KC_RIGHT_GUI , CTL_ENTR
),

//    ┌─────┬─────┬─────┬─────┬─────┬─────┐               ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │     │               │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  ?  │  *  │  #  │  %  │  +  │               │     │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  @  │  &  │  $  │  ~  │  -  │               │  ^  │     │     │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼─────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │     │     │  <  │  >  │     │               │     │     │     │     │     │     │
//    └─────┴─────┴─────┴─────┴─────┼─────┼─────┐   ┌─────┼─────┼─────┴─────┴─────┴─────┴─────┘
//                                  │     │     │   │     │     │
//                                  └─────┴─────┘   └─────┴─────┘
[_CODE_PUNC] = LAYOUT_voyager(
  _______ , _______ , _______ , _______ , _______ , _______  ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_QUES , KC_ASTR , KC_HASH , KC_PERC , KC_PLUS  ,                         _______ , _______ , _______ , _______ , _______ , _______,
  _______ , KC_AT   , KC_AMPR , KC_DLR  , KC_TILD , KC_MINUS ,                         KC_CIRC , _______ , _______ , _______ , _______ , _______,
  _______ , _______ , _______ , KC_LABK , KC_RABK , _______  ,                         _______ , _______ , _______ , _______ , _______ , _______,
                                                    _______  , _______ ,     _______ , _______
),

//    ┌─────┬─────┬─────┬─────┬─────┬──────┐               ┌─────┬─────┬─────┬─────┬─────┬─────┐
//    │     │     │     │     │     │      │               │     │     │  `  │     │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼──────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  *  │  7  │  8  │  9  │  +   │               │     │     │  ^  │  &  │     │     │
//    ├─────┼─────┼─────┼─────┼─────┼──────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  /  │  4  │  5  │  6  │  -   │               │     │     │  $  │  ~  │  |  │     │
//    ├─────┼─────┼─────┼─────┼─────┼──────┤               ├─────┼─────┼─────┼─────┼─────┼─────┤
//    │     │  %  │  1  │  2  │  3  │ calc │               │     │  %  │     │     │     │     │
//    └─────┴─────┴─────┴─────┴─────┼──────┼─────┐   ┌─────┼─────┼─────┴─────┴─────┴─────┴─────┘
//                                  │  0   │     │   │     │     │
//                                  └──────┴─────┘   └─────┴─────┘
[_NUMPAD] = LAYOUT_voyager(
  _______ , _______  , _______ , _______ , _______ , _______       ,                         _______ , _______ , KC_GRAVE , _______ , _______ , _______,
  _______ , KC_ASTR  , KC_7    , KC_8    , KC_9    , KC_PLUS       ,                         _______ , _______ , KC_CIRC  , KC_AMPR , _______ , _______,
  _______ , KC_SLASH , KC_4    , KC_5    , KC_6    , KC_MINUS      ,                         _______ , _______ , KC_DLR   , KC_TILD , KC_PIPE , _______,
  _______ , KC_PERC  , KC_1    , KC_2    , KC_3    , KC_CALCULATOR ,                         _______ , KC_PERC , _______  , _______ , _______ , _______,
                                                     KC_0          , _______ ,     _______ , _______
),

//    ┌────┬────┬────┬────┬────┬────┐             ┌─────────┬───────────┬─────────┬──────┬────┬────┐
//    │ no │ no │ no │ no │ no │ no │             │   no    │    no     │ LGUI(b) │  no  │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼─────────┼──────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ pAGE_UP │ LSFT(tab) │   up    │ tab  │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼─────────┼──────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │  pgdn   │   left    │  down   │ rght │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼─────────┼──────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ LGUI(c) │  LGUI(v)  │  down   │  no  │ no │ no │
//    └────┴────┴────┴────┴────┼────┼────┐   ┌────┼─────────┼───────────┴─────────┴──────┴────┴────┘
//                             │ no │ no │   │ no │   no    │
//                             └────┴────┘   └────┴─────────┘
[_TXT_NAV] = LAYOUT_voyager(
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO      , KC_NO        , LGUI(KC_B) , KC_NO    , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_PAGE_UP , LSFT(KC_TAB) , KC_UP      , KC_TAB   , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_PGDN    , KC_LEFT      , KC_DOWN    , KC_RIGHT , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     LGUI(KC_C) , LGUI(KC_V)   , KC_DOWN    , KC_NO    , KC_NO , KC_NO,
                                          KC_NO , KC_NO ,     KC_NO , KC_NO
),

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
[_MOUSE] = LAYOUT_voyager(
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                          KC_NO          , KC_MS_WH_LEFT , KC_MS_BTN3 , KC_MS_WH_RIGHT , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                          KC_MS_WH_UP    , KC_MS_BTN1    , KC_MS_UP   , KC_MS_BTN2     , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                          KC_MS_WH_DOWN  , KC_MS_LEFT    , KC_MS_DOWN , KC_MS_RIGHT    , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                          KC_RIGHT_SHIFT , LGUI(KC_LBRC) , KC_NO      , LGUI(KC_RBRC)  , KC_NO , KC_NO,
                                          KC_NO , KC_NO ,     KC_MS_BTN1 , KC_MS_BTN2
),

//    ┌────┬────────┬──────────┬────────┬──────────┬───────────┐               ┌─────────┬─────────┬─────────┬─────────┬───────────┬────┐
//    │ no │   no   │ PREV_TAB │   no   │ NXT_TAB  │    no     │               │   no    │ PRV_WIN │ MSN_CTL │ NXT_WIN │    no     │ no │
//    ├────┼────────┼──────────┼────────┼──────────┼───────────┤               ├─────────┼─────────┼─────────┼─────────┼───────────┼────┤
//    │ no │   no   │ WEBSTORM │ FINDER │ PYCHARM  │  SPOTIFY  │               │ VOL_UP  │ LFT_HLF │ FLL_SCR │ RGT_HLF │    no     │ no │
//    ├────┼────────┼──────────┼────────┼──────────┼───────────┤               ├─────────┼─────────┼─────────┼─────────┼───────────┼────┤
//    │ no │ LINEAR │ POSTMAN  │ SLACK  │ TERMINAL │ DATAGRIP  │               │ VOL_DN  │ LFT_23  │  CNTR   │ RGT_23  │ ALACRITTY │ no │
//    ├────┼────────┼──────────┼────────┼──────────┼───────────┤               ├─────────┼─────────┼─────────┼─────────┼───────────┼────┤
//    │ no │   no   │    no    │ CHROME │ SCRN_SHT │ SCRN_SHT2 │               │ KEYMAPP │ L_THRD  │ M_THRD  │ R_THRD  │    no     │ no │
//    └────┴────────┴──────────┴────────┴──────────┼───────────┼────┐   ┌──────┼─────────┼─────────┴─────────┴─────────┴───────────┴────┘
//                                                 │    no     │ no │   │ paus │ PLAY_PS │
//                                                 └───────────┴────┘   └──────┴─────────┘
[_APP] = LAYOUT_voyager(
  KC_NO , KC_NO  , PREV_TAB , KC_NO  , NXT_TAB  , KC_NO     ,                        KC_NO   , PRV_WIN , MSN_CTL , NXT_WIN , KC_NO     , KC_NO,
  KC_NO , KC_NO  , WEBSTORM , FINDER , PYCHARM  , SPOTIFY   ,                        VOL_UP  , LFT_HLF , FLL_SCR , RGT_HLF , KC_NO     , KC_NO,
  KC_NO , LINEAR , POSTMAN  , SLACK  , TERMINAL , DATAGRIP  ,                        VOL_DN  , LFT_23  , CNTR    , RGT_23  , ALACRITTY , KC_NO,
  KC_NO , KC_NO  , KC_NO    , CHROME , SCRN_SHT , SCRN_SHT2 ,                        KEYMAPP , L_THRD  , M_THRD  , R_THRD  , KC_NO     , KC_NO,
                                                  KC_NO     , KC_NO ,     KC_PAUSE , PLAY_PS
),

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
[_FUNC] = LAYOUT_voyager(
  KC_NO , KC_NO , KC_F10 , KC_F11 , KC_F12 , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_F7  , KC_F8  , KC_F9  , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_F4  , KC_F5  , KC_F6  , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_F1  , KC_F2  , KC_F3  , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
                                             KC_NO , KC_NO ,     KC_NO , KC_NO
),

//    ┌────┬────┬────┬────┬────┬────┐             ┌────┬────┬────┬────┬────┬────┐
//    │ no │ no │ no │ no │ no │ no │             │ no │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ no │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ no │ no │ no │ no │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├────┼────┼────┼────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ no │ no │ no │ no │ no │ no │
//    └────┴────┴────┴────┴────┼────┼────┐   ┌────┼────┼────┴────┴────┴────┴────┘
//                             │ no │ no │   │ no │ no │
//                             └────┴────┘   └────┴────┘
[_KEYB] = LAYOUT_voyager(
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,
                                          KC_NO , KC_NO ,     KC_NO , KC_NO
)
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MOUSE_S:
            return TAPPING_TERM + 75;
        case TXT_T:
            return TAPPING_TERM + 75;
        case APP_SP:
            return TAPPING_TERM + 75;
        case NP_N:
            return TAPPING_TERM + 75;
        case CODE_P:
            return TAPPING_TERM + 75;
        case FNC_I:
            return TAPPING_TERM + 75;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
    rgb_matrix_enable();
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




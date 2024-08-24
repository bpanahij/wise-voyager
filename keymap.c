#include QMK_KEYBOARD_H
#include "version.h"
#include "wise_voyager.h"
#include "led_map.c"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_COLEMAK] = LAYOUT_voyager(
//    ┌──────────┬────┬───┬───────────┬───────────┬─────┐                 ┌──────────┬───┬───┬───┬───┬──────┐
//    │   esc    │ no │ _ │ FNC_MINUS │ ESC_COLON │ no  │                 │    no    │ ` │ / │ \ │ % │ bspc │
//    ├──────────┼────┼───┼───────────┼───────────┼─────┤                 ├──────────┼───┼───┼───┼───┼──────┤
//    │    no    │ q  │ w │     f     │     p     │  g  │                 │    j     │ l │ u │ y │ = │  :   │
//    ├──────────┼────┼───┼───────────┼───────────┼─────┤                 ├──────────┼───┼───┼───┼───┼──────┤
//    │   lctl   │ a  │ r │  MOUSE_S  │   TXT_T   │  d  │                 │    h     │ n │ e │ i │ o │  '   │
//    ├──────────┼────┼───┼───────────┼───────────┼─────┤                 ├──────────┼───┼───┼───┼───┼──────┤
//    │ left_ALT │ z  │ x │     c     │     v     │  b  │                 │    k     │ m │ , │ . │ / │  !   │
//    └──────────┴────┴───┴───────────┴───────────┼─────┼──────┐   ┌──────┼──────────┼───┴───┴───┴───┴──────┘
//                                                │ spc │ lsft │   │ lgui │ CTL_ENTR │
//                                                └─────┴──────┘   └──────┴──────────┘
  KC_ESCAPE   , KC_NO , KC_UNDS , FNC_MINUS , ESC_COLON , KC_NO    ,                         KC_NO    , KC_GRAVE , KC_SLASH , KC_BSLS , KC_PERC  , KC_BSPC ,
  KC_NO       , KC_Q  , KC_W    , KC_F      , KC_P      , KC_G     ,                         KC_J     , KC_L     , KC_U     , KC_Y    , KC_EQUAL , KC_COLN ,
  KC_LCTL     , KC_A  , KC_R    , MOUSE_S   , TXT_T     , KC_D     ,                         KC_H     , KC_N     , KC_E     , KC_I    , KC_O     , KC_QUOTE,
  KC_LEFT_ALT , KC_Z  , KC_X    , KC_C      , KC_V      , KC_B     ,                         KC_K     , KC_M     , KC_COMMA , KC_DOT  , KC_SLASH , KC_EXLM ,
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
//    ┌────┬────┬────┬────┬────┬────┐             ┌─────────┬───────────┬──────┬──────┬────┬────┐
//    │ no │ no │ no │ no │ no │ no │             │   no    │    no     │  no  │  no  │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼──────┼──────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │ pAGE_UP │ LSFT(tab) │  up  │ tab  │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼──────┼──────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │  pgdn   │   left    │ down │ rght │ no │ no │
//    ├────┼────┼────┼────┼────┼────┤             ├─────────┼───────────┼──────┼──────┼────┼────┤
//    │ no │ no │ no │ no │ no │ no │             │   no    │    no     │ down │  no  │ no │ no │
//    └────┴────┴────┴────┴────┼────┼────┐   ┌────┼─────────┼───────────┴──────┴──────┴────┴────┘
//                             │ no │ no │   │ no │   no    │
//                             └────┴────┘   └────┴─────────┘
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO      , KC_NO        , KC_NO   , KC_NO    , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_PAGE_UP , LSFT(KC_TAB) , KC_UP   , KC_TAB   , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_PGDN    , KC_LEFT      , KC_DOWN , KC_RIGHT , KC_NO , KC_NO,
  KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                     KC_NO      , KC_NO        , KC_DOWN , KC_NO    , KC_NO , KC_NO,
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
//    ┌────┬────────┬──────────┬────────┬──────────┬───────────┐                    ┌─────────┬─────────┬─────────┬─────────┬───────────┬────┐
//    │ no │   no   │ PREV_TAB │   no   │ NXT_TAB  │           │                    │   no    │ PRV_WIN │ MSN_CTL │ NXT_WIN │    no     │ no │
//    ├────┼────────┼──────────┼────────┼──────────┼───────────┤                    ├─────────┼─────────┼─────────┼─────────┼───────────┼────┤
//    │ no │   q    │ WEBSTORM │ FINDER │ PYCHARM  │  SPOTIFY  │                    │ VOL_UP  │ LFT_HLF │ FLL_SCR │ RGT_HLF │    no     │ no │
//    ├────┼────────┼──────────┼────────┼──────────┼───────────┤                    ├─────────┼─────────┼─────────┼─────────┼───────────┼────┤
//    │ no │ LINEAR │ POSTMAN  │ SLACK  │ TERMINAL │ DATAGRIP  │                    │ VOL_DN  │ LFT_23  │  CNTR   │ RGT_23  │ ALACRITTY │ no │
//    ├────┼────────┼──────────┼────────┼──────────┼───────────┤                    ├─────────┼─────────┼─────────┼─────────┼───────────┼────┤
//    │ no │   no   │    no    │ CHROME │ SCRN_SHT │ SCRN_SHT2 │                    │ KEYMAPP │ L_THRD  │ M_THRD  │ R_THRD  │    no     │ no │
//    └────┴────────┴──────────┴────────┴──────────┼───────────┼─────────┐   ┌──────┼─────────┼─────────┴─────────┴─────────┴───────────┴────┘
//                                                 │  PRV_APP  │ NXT_APP │   │ lgui │ PLAY_PS │
//                                                 └───────────┴─────────┘   └──────┴─────────┘
  KC_NO , KC_NO  , PREV_TAB , KC_NO  , NXT_TAB  , _______   ,                         KC_NO   , PRV_WIN , MSN_CTL , NXT_WIN , KC_NO     , KC_NO,
  KC_NO , KC_Q   , WEBSTORM , FINDER , PYCHARM  , SPOTIFY   ,                         VOL_UP  , LFT_HLF , FLL_SCR , RGT_HLF , KC_NO     , KC_NO,
  KC_NO , LINEAR , POSTMAN  , SLACK  , TERMINAL , DATAGRIP  ,                         VOL_DN  , LFT_23  , CNTR    , RGT_23  , ALACRITTY , KC_NO,
  KC_NO , KC_NO  , KC_NO    , CHROME , SCRN_SHT , SCRN_SHT2 ,                         KEYMAPP , L_THRD  , M_THRD  , R_THRD  , KC_NO     , KC_NO,
                                                  PRV_APP   , NXT_APP ,     KC_LGUI , PLAY_PS
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
            return TAPPING_TERM + 50;
        case TXT_T:
            return TAPPING_TERM + 50;
        case NC_SPACE:
            return TAPPING_TERM + 50;
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
    }
    return true;
}


const uint16_t PROGMEM punctuation_combo[] = {MOUSE_S, TXT_T, COMBO_END};
const uint16_t PROGMEM leave_punctionation_combo[] = {KC_5, KC_6, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_E, KC_N, COMBO_END};
const uint16_t PROGMEM app_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM leave_app_combo[] = {CNTR, RGT_23, COMBO_END};

combo_t key_combos[] = {
    COMBO(punctuation_combo, TG(_NUMPAD)),
    COMBO(leave_punctionation_combo, TG(_NUMPAD)),
    COMBO(esc_combo, KC_ESC),
    COMBO(app_combo, TG(_APP)),
    COMBO(leave_app_combo, TG(_APP)),
};

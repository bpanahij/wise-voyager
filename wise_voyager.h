
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
#define KEYB_BSPC LT(_KEYB, KC_BSPC)

enum voyager_layers {
    _COLEMAK,
    _CODE_PUNC,
    _NUMPAD,
    _TXT_NAV,
    _MOUSE,
    _APP,
    _FUNC,
    _KEYB
};

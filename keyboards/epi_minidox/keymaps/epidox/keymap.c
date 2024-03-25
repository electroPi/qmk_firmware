#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

extern rgblight_config_t rgblight_config;

uint32_t mode;
uint16_t hue;
uint8_t sat;
uint8_t val;


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycode {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |           |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |           |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   K  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *             ,-------------------------.    ,------,-----------------.
 *             | Shift| LOWER/Bksp| CTL  |    | Alt  | DEL/RAISE| LGUI |
 *             | Caps |           |      |    |      |          |      |
 *             `------------------| Space|    | ENTER|----------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_COLEMAK] = LAYOUT(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,         KC_J,    KC_L,    KC_U,     KC_Y,    KC_SCLN,
  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,         KC_H,    KC_N,    KC_E,     KC_I,    KC_O,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_K,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
    LSFT_T(KC_CAPS), LT(_LOWER, KC_BSPC), CTL_T(KC_SPC),     RALT_T(KC_ENT), LT(_RAISE, KC_DEL), KC_LGUI
),


/* Lower
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |   :  |      |   !  |      |           |   ~  |   -  |   =  |   |  |   "  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab |  F3  |  F4  |  F5  |  F6  |           |   `  |   _  |   +  |   \  |   '  |
 * `----------------------------------'           `----------------------------------'
 *             ,-------------------------.    ,------,-----------------.
 *             | Shift| LOWER/Bksp| CTL  |    | Alt  | DEL/RAISE| LGUI |
 *             | Caps |           |      |    |      |          |      |
 *             `------------------| Space|    | ENTER|----------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_LOWER] = LAYOUT( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_ESC,  KC_COLN, _______, KC_EXLM, _______,      KC_TILD, KC_MINS, KC_EQL,  KC_PIPE, KC_DQT,
  KC_TAB,  KC_F3,   KC_F4,   KC_F5,   KC_F6,        KC_GRV,  KC_UNDS, KC_PLUS, KC_BSLS, KC_QUOT,
                    _______, _______, _______,      _______, _______, _______
),


/* Raise
 *
 *  It is the raised layer, because I have the ctrl on the left hand side, the raise on
 *  the right hand side, and the navigations on the left hand side again.
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   !  |   @  |   #  |   $  |   %  |           |   ^  |   &  |   *  |   (  |   )  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Esc |      |  Up  |      |      |           |  INS | HOME | PGUP |   {  |   }  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Tab | Left | Down | Right|      |           |  DEL |  END | PGDN |   [  |   ]  |
 * `----------------------------------'           `----------------------------------'
 *             ,-------------------------.    ,------,-----------------.
 *             | Shift| LOWER/Bksp| CTL  |    | Alt  | DEL/RAISE| LGUI |
 *             | Caps |           |      |    |      |          |      |
 *             `------------------| Space|    | ENTER|----------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 */
[_RAISE] = LAYOUT( \
  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
  KC_ESC,  _______, KC_UP,   _______, _______,      KC_INS,  KC_HOME, KC_PGUP, KC_LCBR, KC_RCBR,
  KC_TAB,  KC_LEFT, KC_DOWN, KC_RGHT, _______,      KC_DEL,  KC_END,  KC_PGDN, KC_LBRC, KC_RBRC,
                    _______, _______, _______,      _______,  _______,  _______
),



/* Adjust (Lower + Raise)
 *
 * ,------------------------------------.           ,----------------------------------.
 * |  F1  |  F2   |  F3  |  F4   |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+-------+------+-------+------|           |------+------+------+------+------|
 * |  F11 |  F12  |      |KC_BRIU|      |           | Mute | Vol- | Vol+ | Mail | Calc |
 * |------+-------+------+-------+------|           |------+------+------+------+------|
 * | Reset|RGB_TOG|      |KC_BRID| Pscr |           | Prev | Stop | Play | Next |caltde|
 * `------------------------------------'           `----------------------------------'
 *             ,-------------------------.    ,------,-----------------.
 *             | Shift| LOWER/Bksp| CTL  |    | Alt  | DEL/RAISE| LGUI |
 *             | Caps |           |      |    |      |          |      |
 *             `------------------| Space|    | ENTER|----------+------.
 *                                |      |    |      |
 *                                `------'    `------'
 *
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 * DO NOT DELETE THE: RESET KEY!!!!! IT HELPS TO PROGRAM THE BOARD!!!!
 * !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 */
[_ADJUST] =  LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
  KC_F11,  KC_F12,  _______, KC_BRIU,  _______,      KC_MUTE, KC_VOLD, KC_VOLU, KC_MAIL, KC_CALC,
  RESET,   RGB_TOG, _______, KC_BRID,  KC_PSCR,      KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, CALTDEL,
                    _______, _______,  _______,      _______,  _______, _______
)
};


#ifdef RGBLIGHT_ENABLE

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv_noeeprom(HSV_BLUE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  mode = rgblight_config.mode;
}


/* This function is handling the layers color updates. */
layer_state_t layer_state_set_user(layer_state_t state) {

  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);

  if (rgblight_is_enabled()) {
    switch(biton32(state)) {
    case 0:
      // Blue
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_BLUE);
      break;
    case 1:
      // Green
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_GREEN);
      break;
    case 2:
      // Red
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_RED);
      break;
    default:
      // Orange
      rgblight_enable_noeeprom();
      rgblight_sethsv_noeeprom(HSV_ORANGE);
      break;
    }
  }

  return state;
}

/* This function is used to set the first LED as a CAPS LOCK inticator. */
void led_set_user(uint8_t usb_led) {

    mode = rgblight_get_mode();
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        rgblight_mode_noeeprom(1);
        rgblight_setrgb_at(0xEE, 0xFF, 0x41, 0);
    } else {
        rgblight_mode(mode);
    }
}

#endif

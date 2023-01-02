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


#define MAXIDOX_HSV_AZURE       132, 102, rgblight_get_val()
#define MAXIDOX_HSV_BLACK         0,   0, rgblight_get_val()
#define MAXIDOX_HSV_BLUE        170, 255, rgblight_get_val()
#define MAXIDOX_HSV_CHARTREUSE   64, 255, rgblight_get_val()
#define MAXIDOX_HSV_CORAL        11, 176, rgblight_get_val()
#define MAXIDOX_HSV_CYAN        128, 255, rgblight_get_val()
#define MAXIDOX_HSV_GOLD         36, 255, rgblight_get_val()
#define MAXIDOX_HSV_GOLDENROD    30, 218, rgblight_get_val()
#define MAXIDOX_HSV_GREEN        85, 255, rgblight_get_val()
#define MAXIDOX_HSV_MAGENTA     213, 255, rgblight_get_val()
#define MAXIDOX_HSV_ORANGE       28, 255, rgblight_get_val()
#define MAXIDOX_HSV_PINK        234, 128, rgblight_get_val()
#define MAXIDOX_HSV_PURPLE      191, 255, rgblight_get_val()
#define MAXIDOX_HSV_RED           0, 255, rgblight_get_val()
#define MAXIDOX_HSV_SPRINGGREEN 106, 255, rgblight_get_val()
#define MAXIDOX_HSV_TEAL        128, 255, rgblight_get_val()
#define MAXIDOX_HSV_TURQUOISE   123,  90, rgblight_get_val()
#define MAXIDOX_HSV_WHITE         0,   0, rgblight_get_val()
#define MAXIDOX_HSV_YELLOW       43, 255, rgblight_get_val()
#define MAXIDOX_HSV_OFF         MAXIDOX_HSV_BLACK


uint16_t hue;
uint8_t sat;
uint8_t val;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak
 *
 * ,----------------------------------.                                      ,----------------------------------.
 * |   Q  |   W  |   F  |   P  |   G  |                                      |   J  |   L  |   U  |   Y  |   ;  |
 * |------+------+------+------+------|                                      |------+------+------+------+------|
 * |   A  |   R  |   S  |   T  |   D  |                                      |   H  |   N  |   E  |   I  |   O  |
 * |------+------+------+------+------|                                      |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |                                      |   K  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------|_______________       ________________|------+------+------+------+------|
 *        | ESC  | TAB  |      | LOW  | BKSP | SPACE |       |  ENT  |  DEL  | RAISE|      |  ALT | CTRL |
 *        +------+------+------+------+------+-------|       |-------+-------+------+------+------+------+
 *                                    | CTRL | SHIFT |       | SUPER | SHIFT |
 *                                    | DEL  | CAPS  |       |       | CAPS  |
 *                                    +------+-------+       +-------+-------+
 *
 */
[_COLEMAK] = LAYOUT(
  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,                                     KC_J,    KC_L,    KC_U,     KC_Y,    KC_SCLN,
  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,                                     KC_H,    KC_N,    KC_E,     KC_I,    KC_O,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                     KC_K,    KC_M,    KC_COMM,  KC_DOT,  KC_SLSH,
  KC_ESC,  KC_TAB,  TT(_LOWER), KC_BSPC, KC_SPC,                                KC_ENT,  KC_DEL,  TT(_RAISE),   KC_RALT, KC_RCTL,
                    LCTL_T(KC_DEL), LSFT_T(KC_CAPS),                KC_LGUI, RSFT_T(KC_CAPS)
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
  _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______,
  _______,_______,_______,_______
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
  _______, _______, _______, _______, _______,      _______, _______,  _______, _______, _______,
  _______,_______,_______,_______
),




/* Adjust (Lower + Raise)
 *
 * ,-----------------------------------.           ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4   |  F5  |           |   F6 |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+-------+------|           |------+------+------+------+------|
 * |  F11 |  F12 |      |KC_ASON|      |           | Mute | Vol- | Vol+ | Mail | Calc |
 * |------+------+------+-------+------|           |------+------+------+------+------|
 * | Reset|      |      |KC_ASOF| Pscr |           | Prev | Stop | Play | Next |caltde|
 * `----------------------------------'           `----------------------------------'
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
  KC_F11,  KC_F12,  RGB_VAI, KC_ASON,  _______,      KC_MUTE, KC_VOLD, KC_VOLU, KC_MAIL, KC_CALC,
  RESET,   RGB_TOG, RGB_VAD, KC_ASOFF, KC_PSCR,      KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, CALTDEL,
  _______, _______, _______, _______,  _______,      _______,  _______, _______, _______,  _______,
  _______,_______,_______,_______
)
};


#ifdef RGBLIGHT_ENABLE

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // Enables RGB, without saving settings
  rgblight_sethsv(MAXIDOX_HSV_BLUE);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
  mode = rgblight_config.mode;
}


/* This function is handling the layers color updates. */
layer_state_t layer_state_set_user(layer_state_t state) {

  state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
  //state = update_tri_layer_state(state, _RAISE, _NUMLAYER, _ADJUST);

  if (rgblight_is_enabled()) {

    switch(biton32(state)) {
    case 0:
      // Blue
      rgblight_enable_noeeprom();
      rgblight_sethsv(MAXIDOX_HSV_BLUE);
      break;
    case 1:
      // Green
      rgblight_enable_noeeprom();
      rgblight_sethsv(MAXIDOX_HSV_GREEN);
      break;
    case 2:
      // Purple
      rgblight_enable_noeeprom();
      rgblight_sethsv(MAXIDOX_HSV_PURPLE);
      break;
    default:
      // Orange
      rgblight_enable_noeeprom();
      rgblight_sethsv(MAXIDOX_HSV_ORANGE);
      break;
    }
  }

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    hue = rgblight_get_hue();
    sat = rgblight_get_sat();
    val = rgblight_get_val();
    mode = rgblight_get_mode();
    // switch (keycode) {
    //     case KC_LGUI:
    //         if (record->event.pressed) {  // IF GUI is pressed,
    //             register_code(KC_LGUI);   // Press KC_LGUI,
    //                                       // rgblight_mode_noeeprom(1);
    //             rgblight_sethsv_at(MAXIDOX_HSV_RED, 3);
    //             rgblight_sethsv_at(MAXIDOX_HSV_RED, 4);
    //             // Custom RGB code                     // Change RGB.
    //         } else {                       // IF GUI is released,
    //             unregister_code(KC_LGUI);  // Release KC_LGUI,
    //             //rgblight_mode(mode);       //### Revert RGB settings
    //             rgblight_sethsv(hue, sat, val);
    //         }
    //         break;
    // }
    return true;
}

/* This function is used to set the first LED as a CAPS LOCK inticator. */
void led_set_user(uint8_t usb_led) {
    mode = rgblight_get_mode();
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        rgblight_mode_noeeprom(1);
        rgblight_sethsv_at(MAXIDOX_HSV_RED, 0);
        rgblight_sethsv_at(MAXIDOX_HSV_RED, 7);
    } else {
        rgblight_mode(mode);
    }
}

#endif

#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define BASE 0
#define META 1
#define SYMB 2
#define GAME 3
#define RGB  4

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

enum custom_keycodes {
  RGB_RST = SAFE_RANGE,
  TAP_ANIM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  | Tab  |   Q  |   W  |   E  |   R  |  T   |   |  Y   |   U  |   I  |   O  |   P  |   [  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  | RCtrl|   A  |   S  |   D  |   F  |  G   |   |  H   |   J  |   K  |   L  |   ;  |   ]  | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | RGB  | LSft |   Z  |   X  |   C  |   V  |  B   |   |  N   |   M  |   ,  |   .  |   /  |  UP  | RSft |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl|   `  |   \  | LAlt | META |Space |   |Space |   '  |   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [BASE] = LAYOUT( \
    KC_DELT, KC_Q,    KC_W,    KC_E,    KC_R,           KC_T,            LGUI(KC_PSCREEN),        KC_JYEN,        KC_Y,     KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,           KC_G,            KC_RBRC,                 KC_BSLS,        KC_H,     KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
    LALT(KC_SPC), KC_Z,    KC_X,    KC_C,    KC_V,           KC_B,            KC_EQL,                  KC_MINS,        KC_N,     KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RO, \
    KC_LGUI, TG(RGB), XXXXXXX, KC_LALT, LCTL_T(KC_GRV), LT(SYMB,KC_SPC), KC_LSFT,                KC_BSPC, MO(META), KC_ENT, KC_RCTL, XXXXXXX, KC_RALT, KC_RGUI \
  ),

  /* META
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | Reset|   1  |   2  |   3  |   4  |   5  |  [   |   |  ]   |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  |  F1  |      |Muhen | Henk |      |      |   | Left | Down |  Up  |Right |      |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | RGB  |  F2  |  F3  |  F4  |  F5  |  F6  |  {   |   |  }   |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl|   `  |   \  | LAlt | META |Space |   |Space |   '  |   -  |   =  |      |      |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [META] = LAYOUT( \
    RESET,   KC_F1,   KC_F2,  KC_F3,   KC_F4,   KC_F5, XXXXXXX,      XXXXXXX,   KC_F6,    KC_F7,   KC_F8,   KC_F9,  KC_F10,    XXXXXXX, \
    _______, KC_F11, XXXXXXX, KC_MHEN, KC_HENK, XXXXXXX, XXXXXXX,      KC_HOME,   KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT, KC_END, XXXXXXX, \
    _______, KC_F12, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,  XXXXXXX,  KC_PGDOWN,  KC_PGUP,  XXXXXXX, XXXXXXX,  XXXXXXX, \
    _______, _______, _______, _______, _______, _______, _______,      _______,    _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX \
  ),

  /* SYMB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * | ESC  |   !  |   @  |   #  |   $  |   %  |  [   |   |  ]   |   ^  |   &  |   *  |   (  |   )  | Bksp |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * | Del  |      |      |      |      |      |  (   |   |  )   |      |      |      |      |      | Enter|
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * | RGB  |      |      |      |      |      |  {   |   |  }   |      |      |      |      |  UP  | Sft  |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * | LGUI | LCtrl|   `  |   \  | LAlt | META |Space |   |Space |   '  |   -  |   =  | LEFT | DOWN | RIGHT|
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [SYMB] = LAYOUT( \
    _______, KC_1,    KC_2,      KC_3,    KC_4,      KC_5,    _______,        _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______, \
    _______, S(KC_1), S(KC_2),   S(KC_3), S(KC_4),   S(KC_5), _______,        _______, S(KC_6), S(KC_7), S(KC_8), S(KC_9), _______, _______, \
    _______, KC_EQL,  S(KC_EQL), S(KC_MINS),KC_MINS, S(KC_JYEN), _______,     _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,        _______,    _______, _______, _______, _______, _______, _______ \
  ),

  /* RGB
   * ,------------------------------------------------.   ,------------------------------------------------.
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+------|   |-------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      | TOG  | HUI  | SAI  | VAI  |HUANIM|      |
   * |------+------+------+------+------+------+------|   |------|------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      | MOD  | HUD  | SAD  | VAD  |RESET |      |
   * |------+------+------+------+------+------+------|   |------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |   |      |      |      |      |      |=>RGB |      |
   * `------------------------------------------------'   `------------------------------------------------'
   */
  [RGB] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, TAP_ANIM,XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUI, RGB_SAD, RGB_VAD, RGB_RST, XXXXXXX, \
    XXXXXXX, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX \
  )

};

bool isTapAnim = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_MOD:
      if (record->event.pressed) {
        isTapAnim = false;
      }
      break;
    case RGB_RST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
        }           
      #endif
      break;
    case TAP_ANIM:
      if (record->event.pressed) {
        isTapAnim = !isTapAnim;
      }
      break;
  }

  if (isTapAnim) {
    rgblight_mode_noeeprom(1);
    uint16_t hue = (rgblight_config.hue + 5) % 360;
    rgblight_sethsv_noeeprom(hue, rgblight_config.sat, rgblight_config.val);
  }

  return true;
}


#include QMK_KEYBOARD_H

#define CTL_Z       CTL_T(KC_Z)
#define ALT_X       ALT_T(KC_X)
#define ALT_COMM    ALGR_T(KC_COMM)
#define CTL_DOT     RCTL_T(KC_DOT)
#define SFT_TAB     RSFT_T(KC_TAB)

#define LT_T        LT(3, KC_T)
#define LT_SPC_L    LT(2, KC_SPC)
#define LT_SPC_R    LT(1, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // Colemak DH-mod
  [0] = LAYOUT_ortho_3x10(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,       KC_Y,      KC_BSPC,
    KC_A,    KC_R,    KC_S,    LT_T,    KC_G,    KC_K,    KC_N,    KC_E,       KC_I,      KC_O,
    CTL_Z,   ALT_X,   KC_C,    KC_D,    KC_V,    KC_M,    KC_H,   ALT_COMM,   CTL_DOT,   SFT_TAB,
                                        LT_SPC_L, LT_SPC_R
  ),

  // Numbers layer
  [1] = LAYOUT_ortho_3x10(
    KC_PSLS, KC_7,    KC_8,    KC_9,    KC_PPLS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BSPC,
    KC_0,    KC_4,    KC_5,    KC_6,    KC_PMNS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, KC_QUOT,
    KC_LSFT, KC_1,    KC_2,    KC_3,    KC_PEQL, XXXXXXX, XXXXXXX, _______, _______, KC_ENT,
                                        _______, _______
  ),

  // Symbols layer
  [2] = LAYOUT_ortho_3x10(
    KC_EXLM, KC_AMPR, KC_ASTR, KC_PIPE, XXXXXXX, KC_EXLM, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN,
    KC_DEL,  KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_GRV,
    KC_LSFT, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, KC_TILD, KC_PIPE, _______, _______, KC_BSLS,
                                        _______, _______
  ),

  // Navigation layer
  [3] = LAYOUT_ortho_3x10(
    KC_ESC,  KC_WH_U, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D,  KC_WH_U, XXXXXXX, KC_BSPC,
    KC_TAB,  KC_LALT, KC_LGUI, _______, XXXXXXX, KC_LEFT, KC_DOWN,  KC_UP,   KC_RGHT, KC_BSPC,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME,  KC_END,  XXXXXXX, KC_ENT,
                                        _______, _______
  ),

  // Adjust layer
  [4] = LAYOUT_ortho_3x10(
      RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_MUTE, KC_MNXT, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                        _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, 1, 2, 4);
}

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.

  // Set our LED pins as output
  setPinOutput(D5);
  setPinOutput(B0);
}

void led_set_user(uint8_t usb_led) {
  if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    writePinLow(D5);
  } else {
    writePinHigh(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    writePinLow(B0);
  } else {
    writePinHigh(B0);
  }
}

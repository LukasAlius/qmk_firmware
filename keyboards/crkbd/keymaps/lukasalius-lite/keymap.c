#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum layer_names {
  _BASE,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAV
};

enum special_keycodes {
    BASE = SAFE_RANGE,
    GAME
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LT_T LT(_NAV, KC_T)
#define CT_BSPC LCTL_T(KC_BSPC)
#define AL_X  LALT_T(KC_X)
#define AL_DOT LALT_T(KC_DOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_R,    KC_S,    LT_T,    KC_G,                         KC_K,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LGUI,    KC_Z,    AL_X,    KC_C,    KC_D,    KC_V,                         KC_M,    KC_H, KC_COMM,  AL_DOT, KC_SLSH,  KC_ENT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LSFT,  CT_BSPC, KC_SPC,   OSM(MOD_LSFT), RAISE,  LOWER \
                                      //`--------------------------'  `--------------------------'

  ),

  [_GAME] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_E,    KC_W,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_LSFT,    KC_F,    KC_A,    KC_S,    KC_D,   KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        KC_LSFT,  KC_LCTL, KC_SPC,     KC_LGUI, RAISE,  LOWER \
                                      //`--------------------------'  `--------------------------'

  ),

  [_LOWER] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC, KC_PSLS,  KC_7,    KC_8,    KC_9,   KC_PPLS,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLN,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_DEL,   KC_0,   KC_4,    KC_5,    KC_6,   KC_PMNS,                      KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT, XXXXXXX, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_ASTR,  KC_1,    KC_2,    KC_3,   KC_PEQL,                      XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
    ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC, KC_EXLM,  KC_AMPR, KC_ASTR, XXXXXXX, XXXXXXX,                      KC_EXLM, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, KC_DEL, KC_DLR, KC_PERC, KC_CIRC,    XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSPC,  KC_GRV,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, KC_EXLM, KC_AT, KC_HASH, XXXXXXX,                      XXXXXXX, KC_PIPE, KC_COMM, KC_DOT, KC_BSLS, KC_TILD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLU,                      XXXXXXX,    BASE,    GAME, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MNXT, KC_VOLD,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),

  [_NAV] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_ESC, XXXXXXX, KC_WH_U, KC_WH_D,  XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_D, KC_WH_U, XXXXXXX, XXXXXXX, KC_BSPC,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_TAB, KC_DEL, KC_LALT, KC_LGUI, _______, XXXXXXX,                        KC_LEFT,  KC_DOWN, KC_UP, KC_RGHT, KC_BSPC,  XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_HOME, KC_END, XXXXXXX, XXXXXXX, XXXXXXX,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______,   _______,  _______,     _______,   _______, _______ \
                                      //`--------------------------'  `--------------------------'
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BASE:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAME);
      }
      return false;
      break;
  }
  return true;
}
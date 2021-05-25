/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NAV,
    _NUM,
    _DEV,
    _SYMBL,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#define LT_S LT(_DEV, KC_S)
#define LT_T LT(_NAV, KC_T)

#define LT_N LT(_NUM, KC_N)
#define LT_E LT(_SYMBL, KC_E)

#define SF_SPC LSFT_T(KC_SPC)

#define CT_BSPC LCTL_T(KC_BSPC)
#define SF_BSPC LSFT_T(KC_BSPC)
#define SF_Z  LSFT_T(KC_Z)
#define SF_QT  RSFT_T(KC_QUOT)
#define AL_X  LALT_T(KC_X)
#define AL_DOT LALT_T(KC_DOT)



// Blank template at the bottom
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Qwerty
 *
 * ,-----------------------------.      ,-----------------------------.
 * |  Q  |  W  |  F  |  P  |  B  |      |  J  |  L  |  U  |  Y  |  ;  |
 * |-----+-----+-----+-----+-----|      |-----------------------------|
 * |  A  |  R  |  S  |  T  |  G  |      |  K  |  N  |  E  |  I  |  O  |
 * |-----+-----+-----+-----+-----+      |-----------------------------|
 * |  Z  |  X  |  C  |  D  |  V  |      |  M  |  H  |  <  |  >  |  ?  |
 * `-----+-----+-----+-----+-----+--. ,-+-----------------------------'
 *                    | LOWER | SPC | | LOWER | RAISE |
 *                     '------------' '-----------'
 */
[_BASE] = LAYOUT(
    KC_Q, KC_W, KC_F, KC_P, KC_B,       KC_J, KC_L, KC_U,    KC_Y,   KC_QUOT,
    KC_A, KC_R, LT_S, LT_T, KC_G,       KC_K, LT_N, KC_E,    KC_I,   KC_O,
    KC_Z, AL_X, KC_C, KC_D, KC_V,       KC_M, KC_H, KC_COMM, AL_DOT, KC_SLSH,
                     CT_BSPC, SF_SPC,   RAISE, LT(RAISE, KC_TAB) //OSL(RAISE)
),
[_LOWER] = LAYOUT(
    KC_1,     KC_2,     KC_3,     KC_4,     KC_5,           XXXXXXX,  XXXXXXX,  KC_LT,  KC_GT,  KC_GRV,
    KC_6,     KC_7,     KC_8,     KC_9,     KC_0,           KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_BSPC,
    KC_ESC,   KC_LALT,  KC_LGUI,  XXXXXXX,  KC_ENT,         KC_TAB,   KC_HOME,  KC_END,   KC_LSFT,  KC_SLSH,
                                  _______,  _______,       _______,   _______
),
[_RAISE] = LAYOUT(
    KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,            KC_EXLM,  KC_COLN,  KC_LPRN,  KC_RPRN,  KC_SCLN,
    KC_CIRC,  KC_AMPR,  KC_ASTR,  XXXXXXX,  XXXXXXX,            KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSPC,
    KC_ESC,   KC_LALT,  KC_LGUI,  KC_LSFT,  KC_ENT,             KC_TAB,  KC_PIPE,  KC_COMM,  KC_DOT,  KC_BSLS,
                                      _______,  _______,    LOWER, _______
),
[_ADJUST] = LAYOUT(
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,              KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,
    KC_F11,   KC_F12,   XXXXXXX,  KC_MPLY,  KC_VOLU,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
    XXXXXXX,  XXXXXXX,  KC_MUTE,  KC_MNXT,  KC_VOLD,            XXXXXXX,  XXXXXXX,  XXXXXXX,  RESET,    XXXXXXX,
                                      _______,  _______,    _______, _______
),
[_NAV] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN,
    KC_DEL, KC_LALT, KC_LGUI,  _______, XXXXXXX,           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,           KC_ENT,  KC_HOME, KC_END,  XXXXXXX, XXXXXXX,
                                _______, _______,         _______, KC_TAB
),
[_NUM] = LAYOUT(
    KC_PSLS, KC_7,    KC_8,    KC_9, KC_PPLS,              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_COLN,
    KC_0,    KC_4,    KC_5,    KC_6, KC_PMNS,              XXXXXXX, _______, XXXXXXX, XXXXXXX, KC_BSPC,
    KC_ASTR, KC_1,    KC_2,    KC_3, KC_PEQL,              KC_ENT,  XXXXXXX, KC_COMM, KC_DOT,  KC_DEL,
                                _______, _______,         _______,  KC_TAB
),
[_DEV] = LAYOUT(
    KC_ESC,  KC_ASTR, XXXXXXX, KC_UP,   XXXXXXX,              KC_EXLM, KC_COLN, KC_LPRN, KC_RPRN, KC_SCLN,
    KC_DEL,  XXXXXXX, _______, KC_LEFT, KC_RGHT,              KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSPC,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, XXXXXXX,              KC_ENT,  KC_PIPE, KC_COMM, KC_DOT,  KC_BSLS,
                                _______, _______,         _______,  KC_TAB
),
[_SYMBL] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_ASTR, XXXXXXX,
    KC_QUOT, KC_DQUO, KC_GRV,  XXXXXXX, XXXXXXX,              XXXXXXX, XXXXXXX, _______, XXXXXXX, KC_BSPC,
    XXXXXXX, XXXXXXX, KC_LT,   KC_GT,   XXXXXXX,              KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,
                                _______, _______,         _______,  KC_TAB
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
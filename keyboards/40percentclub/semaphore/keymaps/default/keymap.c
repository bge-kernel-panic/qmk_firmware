/* Copyright 2018
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _ADJUST 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------------------------------------------------.
   * |  ESC |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   -  |
   * |------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
   * |------+------+------+------+------|------+------+------+------+------+------+------|
   * |Lshift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |'/Shft|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Home | PgDn | PgUp |  End | Gui  |Space |Layer |  Alt | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY] = LAYOUT_split(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINUS,\
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,  \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, LSFT_T(KC_QUOTE), \
    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_LGUI, KC_SPC,  MO(1),   KC_LALT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------.
   * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |   +  |
   * |------+------+------+------+------|------+------+------+------+------+------+------|
   * |  ~   |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |Insert|      | PrtSc|   =  |
   * |------+------+------+------+-------------+------+------+------+------+------+------|
   * |`/Ctrl| Pause|ScrLk |  Del |   [  |   {  |   }  |   ]  |      |      |   |  |      |
   * |------+------+------+------+------|------+------+------+------+------+------+------|
   * |Lshift|      |      |      |      |      |      | Mute | Vol- | Vol+ |   \  |Rshift|
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      | MO(2)|      |      | Prev | Stop | Play | Next |
   * `-----------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_split( \
    _______,        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, KC_PLUS, \
    KC_TILD,        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, KC_INS,  _______, KC_PSCR, KC_EQUAL,\
    LCTL_T(KC_GRV), KC_PAUS, KC_SLCK, KC_DEL,  KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, _______, _______, KC_PIPE, _______, \
    _______,        _______, _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, _______, \
    _______,        _______, _______, _______, _______, MO(2),   _______, _______, KC_MPRV, KC_STOP, KC_MPLY, KC_MNXT  \
  ),
  /* Adjust
   * ,-----------------------------------------------------------------------------------.
   * | RESET|      |      |      |      |      |      |      | NumLk|   /  |   *  |   -  |
   * |------+------+------+------+------|------+------+------+------+------+------+------|
   * |      |      |      |      |      | NKRO |      |      |   7  |   8  |   9  |   +  |
   * |------+------+------+------+-------------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |   4  |   5  |   6  | Enter|
   * |------+------+------+------+------|------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |   1  |   2  |   3  |   =  |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |   0  |   0  |   .  |   .  |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_split( \
    RESET,   _______, _______, _______, _______, _______,  _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS, \
    _______, _______, _______, _______, _______, NK_TOGG,  _______, _______, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, \
    _______, _______, _______, _______, _______, _______,  _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PENT, \
    _______, _______, _______, _______, _______, _______,  _______, _______, KC_P1,   KC_P2,   KC_P3,   KC_PEQL, \
    _______, _______, _______, _______, _______, _______,  _______, _______, KC_P0,   KC_P0,   KC_PDOT, KC_PDOT  \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {

}

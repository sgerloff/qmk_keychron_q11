/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

enum layers{
    CUSTOM_BASE,
    CUSTOM_SYM,
    WIN_BASE,
    WIN_FN,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define OSL_CFN OSL(WIN_FN)
#define OSL_SYM OSL(CUSTOM_SYM)
// #define OSM_HYPR OSM(MOD_HYPR)
#define OSM_LSPR OSM(MOD_LCTL | MOD_LSFT | MOD_LGUI)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LALT OSM(MOD_LALT)
#define OSM_RSFT OSM(MOD_RSFT)
#define OSM_RCTL OSM(MOD_RCTL)
#define OSM_RGUI OSM(MOD_RGUI)
#define OSM_RALT OSM(MOD_RALT)

// Symbols
#define DE_EXLM    S(KC_1)    // !
#define DE_DQUO    S(KC_2)    // "
#define DE_HASH    S(KC_3)    // #
#define DE_DLR     S(KC_4)    // $
#define DE_PERC    S(KC_5)    // %
#define DE_AMPR    S(KC_6)    // &
#define DE_SLSH    S(KC_7)    // /
#define DE_LPRN    S(KC_8)    // (
#define DE_RPRN    S(KC_9)    // )
#define DE_EQL     S(KC_0)    // =
#define DE_QUES    S(KC_MINS) // ?
                              //
#define DE_FTIK    KC_EQL     // ´
#define DE_BTIK    S(KC_EQL)  // `

#define DE_PLUS    KC_RBRC    // +
#define DE_ASTR    S(KC_RBRC) // *

#define DE_LANG    KC_NUBS    // <
#define DE_RANG    S(KC_NUBS) // >

#define DE_SQUO    S(KC_NUHS) // '
#define DE_MIN     KC_SLSH    // -
#define DE_UNDS    S(KC_SLSH) // _
#define DE_COLN    S(KC_DOT)  // :
#define DE_SCOL    S(KC_COMM) // ;

#define DE_AT     RALT(KC_Q)    // @
#define DE_LBRC   RALT(KC_8)    // [
#define DE_RBRC   RALT(KC_9)    // ]
#define DE_LCBR   RALT(KC_7)    // {
#define DE_RCBR   RALT(KC_0)    // {
#define DE_BSLH   RALT(KC_MINS) //
#define DE_TILD   RALT(KC_RBRC) // ~
#define DE_PIPE   RALT(KC_NUBS) // |

const uint16_t PROGMEM l_ctrl_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM l_gui_combo[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM l_alt_combo[] = {KC_E, KC_S, COMBO_END};
const uint16_t PROGMEM l_ctrl_gui_combo[] = {KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM l_ctrl_alt_combo[] = {KC_E, KC_F, COMBO_END};
const uint16_t PROGMEM l_ctrl_shift_combo[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM l_gui_shift_combo[] = {KC_D, KC_G, COMBO_END};

const uint16_t PROGMEM r_ctrl_combo[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM r_gui_combo[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM r_alt_combo[] = {KC_I, KC_L, COMBO_END};
const uint16_t PROGMEM r_ctrl_gui_combo[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM r_ctrl_alt_combo[] = {KC_J, KC_I, COMBO_END};
const uint16_t PROGMEM r_ctrl_shift_combo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM r_gui_shift_combo[] = {KC_H, KC_K, COMBO_END};

combo_t key_combos[] = {
  COMBO(l_ctrl_combo, OSM_LCTL),
  COMBO(l_gui_combo, OSM_LGUI),
  COMBO(l_alt_combo, OSM_LALT),
  COMBO(l_ctrl_gui_combo, OSM(MOD_LCTL | MOD_LGUI)),
  COMBO(l_ctrl_alt_combo, OSM(MOD_LCTL | MOD_LALT)),
  COMBO(l_ctrl_shift_combo, OSM(MOD_LCTL | MOD_LSFT)),
  COMBO(l_gui_shift_combo, OSM(MOD_LGUI | MOD_LSFT)),
  COMBO(r_ctrl_combo, OSM_RCTL),
  COMBO(r_gui_combo, OSM_RGUI),
  COMBO(r_alt_combo, OSM_LALT),
  COMBO(r_ctrl_gui_combo, OSM(MOD_RCTL | MOD_RGUI)),
  COMBO(r_ctrl_alt_combo, OSM(MOD_RCTL | MOD_LALT)),
  COMBO(r_ctrl_shift_combo, OSM(MOD_RCTL | MOD_RSFT)),
  COMBO(r_gui_shift_combo, OSM(MOD_RGUI | MOD_RSFT)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CUSTOM_BASE] = LAYOUT_92_iso(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,   KC_END,   KC_MUTE,
         KC_F20,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
         KC_F19,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
         KC_F18,  KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
         KC_F17, KC_LSFT,   KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             KC_RSFT,   KC_UP,
         KC_F16,OSM_LCTL,  OSM_LGUI, OSM_LALT,OSM_LSPR,  LT(CUSTOM_SYM, KC_SPC),                      OSL_SYM,          OSM_RALT, OSL_CFN,OSM_RCTL,   KC_LEFT,  KC_DOWN,  KC_RGHT),

    [CUSTOM_SYM] = LAYOUT_92_iso(
        KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  KC_MUTE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,    DE_AT,  DE_LANG,  DE_RANG,   DE_EQL,  DE_FTIK,   DE_BTIK,   DE_EQL,  DE_PLUS,  DE_ASTR,   DE_MIN,  _______,    DE_TILD,                      _______,
        _______,  _______,  DE_LPRN,  DE_LCBR,  DE_LBRC,  DE_DQUO,  DE_SLSH,   DE_BSLH,  DE_DQUO,  DE_RBRC,  DE_RCBR,  DE_RPRN,  _______,    _______,  _______,            _______,
        _______,  _______,  DE_PIPE,  _______,  _______,  _______,  DE_SQUO,   DE_TILD,  _______,  DE_SQUO,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_92_iso(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_MUTE,
        _______,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        _______,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_PGDN,
        _______,  KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_HOME,
        _______,  KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        _______,  KC_LCTL,  KC_LWIN,  KC_LALT,  MO(WIN_FN),         KC_SPC,                        KC_SPC,             KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_92_iso(
        RM_TOGG,  _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,   RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  _______,  RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,   _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,
        _______,  _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [CUSTOM_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [CUSTOM_SYM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU), ENCODER_CCW_CW(RM_VALD, RM_VALU) }
};
#endif // ENCODER_MAP_ENABLE

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
    CUSTOM_NAV,
    WIN_BASE,
    WIN_FN,
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define OSL_CFN OSL(WIN_FN)
#define OSL_SYM OSL(CUSTOM_SYM)
// #define OSM_HYPR OSM(MOD_HYPR)
#define OSM_LSPR OSM(MOD_LCTL | MOD_LSFT | MOD_LGUI)

// Symbols
#define DE_EXLM    S(KC_1)    // !
#define DE_DQUO    S(KC_2)    // "
#define DE_HASH    KC_NUHS    // #
#define DE_LEGL    S(KC_3)    // #
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

#define LT_G LT(CUSTOM_SYM, KC_G)
#define MT_F LCTL_T(KC_F)
#define MT_D LGUI_T(KC_D)
#define MT_S LALT_T(KC_S)

#define LT_H LT(CUSTOM_SYM, KC_H)
#define MT_J RCTL_T(KC_J)
#define MT_K RGUI_T(KC_K)
#define MT_L LALT_T(KC_L)


enum tap_dance{
  TD_LBRC_RBRC,
  TD_LCBR_RCBR,
  TD_LPRN_RPRN,
  TD_LANG_RANG,
  TD_SLSH_BSLH,
  TD_DQUO_SQUO,
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_RBRC] = ACTION_TAP_DANCE_DOUBLE(DE_LBRC, DE_RBRC),
  [TD_LCBR_RCBR] = ACTION_TAP_DANCE_DOUBLE(DE_LCBR, DE_RCBR),
  [TD_LPRN_RPRN] = ACTION_TAP_DANCE_DOUBLE(DE_LPRN, DE_RPRN),
  [TD_LANG_RANG] = ACTION_TAP_DANCE_DOUBLE(DE_LANG, DE_RANG),
  [TD_SLSH_BSLH] = ACTION_TAP_DANCE_DOUBLE(DE_SLSH, DE_BSLH),
  [TD_DQUO_SQUO] = ACTION_TAP_DANCE_DOUBLE(DE_DQUO, DE_SQUO),
};

#define TD_BRC TD(TD_LBRC_RBRC)
#define TD_CBR TD(TD_LCBR_RCBR)
#define TD_PRN TD(TD_LPRN_RPRN)
#define TD_ANG TD(TD_LANG_RANG)
#define TD_SLH TD(TD_SLSH_BSLH)
#define TD_QUO TD(TD_DQUO_SQUO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [CUSTOM_BASE] = LAYOUT_92_iso(
        KC_MUTE,  KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,   KC_END,   KC_MUTE,
         KC_F20,  KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
         KC_F19,  KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     DE_COLN,    KC_RBRC,                      KC_PGDN,
         KC_F18,  KC_ESC,   KC_A,     MT_S,     MT_D,     MT_F,     LT_G,      LT_H,     MT_J,     MT_K,     MT_L,     KC_SCLN,  DE_UNDS,    KC_NUHS,  KC_ENT,             KC_HOME,
         KC_F17, OS_LSFT,   KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,             OS_RSFT,   KC_UP,
         KC_F16, OS_LCTL,   OS_LGUI,  OS_LALT, OSL(CUSTOM_NAV),                 KC_SPC,               OS_LSFT,         OS_RALT,  OSL_CFN,    OS_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT),

    [CUSTOM_SYM] = LAYOUT_92_iso(
        KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  KC_MUTE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,    DE_AT,  DE_QUES,  DE_TILD,  DE_AMPR,  DE_PLUS,   DE_ASTR,  KC_LBRC,  DE_QUES,  _______,  KC_MINS,  _______,    _______,                      _______,
        _______,  _______,  KC_QUOT,  DE_EXLM,  DE_DQUO,   DE_EQL,  DE_SLSH,   DE_BSLH,  DE_LPRN,  DE_LBRC,  DE_LCBR,  DE_FTIK,  DE_BTIK,    _______,  _______,            _______,
        _______,  _______,  DE_PIPE,  _______,  DE_SQUO,  DE_PERC,  DE_HASH,   _______,  _______,  DE_RPRN,  DE_RBRC,  DE_RCBR,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [CUSTOM_NAV] = LAYOUT_92_iso(
        KC_MUTE,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  KC_MUTE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,  _______,  _______,    _______,                      _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    uint8_t mods = get_oneshot_mods();
    if (mods & MOD_MASK_SHIFT) {
      if ((keycode >= KC_A && keycode <= KC_0) || (keycode >= KC_MINUS && keycode <= KC_SLASH)) {
        clear_oneshot_mods();
        add_mods(mods);
        send_keyboard_report();
        wait_ms(5);
        register_code(keycode);
        send_keyboard_report();
        wait_ms(5);
        unregister_code(keycode);
        del_mods(mods);
        send_keyboard_report();
        return false;
      }
    }
  }
  return true;
}


// const key_override_t lbrc_to_rbrc_override = ko_make_with_layers_and_negmods(
//     MOD_MASK_SHIFT,
//     KC_BSPC,
//     KC_DEL,
//     0xFFFF,
//     0
// );
//
// const key_override_t *key_overrides[] = (const key_override_t *[]) {
//   &lbrc_to_rbrc_override,
//   NULL
// };


#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_92_iso(
  // Row 0: Macro + Esc + F1-F6 (L), F7-F12 + Nav (R)
  'L',  'L', 'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  // Row 1: Macro + ` + 1-5 (L), 6-0 + Symbols + BSPC + PgUp (R)
  'L',  'L', 'L', 'L', 'L', 'L', 'L',         'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  // Row 2: Macro + Tab + Q-T (L), Y-P + [ ] + PgDn (R)
  'L',  'L', 'L', 'L', 'L', 'L', 'L',         'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  // Row 3: Macro + Caps + A-G (L), H-' + # + Enter + Home (R)
  'L',  'L', 'L', 'L', 'L', 'L', 'L',         'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R', 'R',
  // Row 4: Macro + Shift + \ + Z-B (L), N-/ + Shift + Up (R)
  'L',  'L', 'L', 'L', 'L', 'L', 'L', 'L',    'R', 'R', 'R', 'R', 'R', 'R', 'R',
  // Row 5: Macro + Mods + Space (L), Space + Mods + Arrows (R)
  'L',  'L', 'L', 'L', 'L', 'L',              'R', 'R', 'R', 'R', 'R', 'R', 'R'
);
#endif

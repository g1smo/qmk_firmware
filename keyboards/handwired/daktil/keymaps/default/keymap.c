#include "daktil.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define TKTK 3 // Tehnoklistir layer

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  VRSN,
  DYNAMIC_MACRO_RANGE
};

#include "dynamic_macro.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.              ,-----------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |              |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  |              |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * | BkSp |   A  |   S  |   D  |   F  |   G  |              |   H  |   J  |   K  |   L  |; / L2|'/Cmd |
 * |------+------+------+------+------+------|              |------+------+------+------+------+------|
 * |LSft/(|Z/Ctrl|   X  |   C  |   V  |   B  |              |   N  |   M  |   ,  |   .  |//Ctrl|RSft/)|
 * `------+------+------+------+------+------'              `------+------+------+------+------+------'
 *               | LAlt |Insert|                                          |   [  |   ]  |
 *               `-------------'                                          `-------------'
 *                        ,------,------.                   ,------------.
 *                        |      |      |                   |      |     |
 *                        |  Spc | Bksp |-----.       ,-----+  Tab |Enter|
 *                        |      |      |Esc/m|       |Esc/m|      |     |
 *                        |------+------+-----|       |-----+------+-----|
 *                        | Lalt |  End |Home |       | PgUp| PgDn | Ralt|
 *                        `------+------+-----'       `-----+------+-----'
 */
[BASE] = LAYOUT_dactyl(  // layer 0 : default
        // left hand
    LALT(KC_LSFT),         KC_1,           KC_2,     KC_3,    KC_4,   KC_5,
  LT(TKTK,KC_EQL),         KC_Q,           KC_W,     KC_E,    KC_R,   KC_T,
          KC_LSPO,         KC_A,           KC_S,     KC_D,    KC_F,   KC_G,
  LT(SYMB,KC_GRV),  CTL_T(KC_Z),           KC_X,     KC_C,    KC_V,   KC_B,
                                        KC_DELT,   KC_INS,  KC_SPC,KC_BSPC,
                                            ALT_T(KC_APP),  LGUI_T(KC_ESC),
                                                   KC_END,         KC_HOME,
        // right hand
                             KC_6,   KC_7,     KC_8,     KC_9,               KC_0,         KC_MINS,
                             KC_Y,   KC_U,     KC_I,     KC_O,               KC_P,LT(TKTK,KC_BSLS),
                             KC_H,   KC_J,     KC_K,     KC_L,  LT(MDIA, KC_SCLN),         KC_RSPC,
                             KC_N,   KC_M,  KC_COMM,   KC_DOT,     CTL_T(KC_SLSH),LT(SYMB,KC_QUOT),
                           KC_TAB, KC_ENT,  KC_LBRC,  KC_RBRC,
                   LGUI_T(KC_ESC), KC_RALT,
                          KC_PGUP, KC_PGDN
    ),
/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Versn |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   {  |   }  |   |  |                    |   &  |   7  |   8  |   9  |   *  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   $  |   (  |   )  |   `  |                    |   ^  |   4  |   5  |   6  |   +  |   =  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |                    |   _  |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |RESET |      |      |      |      |                                  |      |   .  |   0  |
 * `----------------------------------'                                  `--------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |      |
 *                               |      |      |------|  |------|      |      |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_dactyl(
       // left hand
       KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
          VRSN,  KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,
       KC_TRNS,  KC_HASH,   KC_DLR,  KC_LPRN,  KC_RPRN,   KC_GRV,
       KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,
                           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                                               KC_TRNS,  KC_TRNS,
                                               KC_TRNS,  KC_TRNS,
       // right hand
                KC_F6,      KC_F7,   KC_F8, KC_F9,  KC_F10,   KC_F11,
                KC_AMPR,     KC_7,    KC_8,  KC_9, KC_ASTR,   KC_F12,
                KC_CIRC,     KC_4,    KC_5,  KC_6, KC_PLUS,   KC_EQL,
                KC_UNDS,     KC_1,    KC_2,  KC_3, KC_MINS,  KC_TRNS,
                KC_TRNS,  KC_TRNS,  KC_DOT,  KC_0,
                KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_TRNS
),
/* Keymap 2: Media and mouse keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | MsUp |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MsLeft|MsDown|MsRght|      |                    |      |      |      |      |      | Play |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      | Prev | Next |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      |      |      | Lclk | Rclk |                                  | VolUp| VolDn| Mute |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |      |  |      |      |Brwser|
 *                               |      |      |------|  |------|      |Back  |
 *                               |      |      |      |  |      |      |      |
 *                               `--------------------'  `--------------------'
 *
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_dactyl(
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
         RESET,  KC_TRNS,  KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                           KC_TRNS,  KC_TRNS,  KC_BTN1,  KC_BTN2,
                                               KC_MPLY,  KC_BTN3,
                                               KC_MPRV,  KC_MNXT,
    // right hand
                  RESET,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                  RESET,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,
                KC_LEFT,  KC_DOWN,    KC_UP,  KC_RIGHT, KC_TRNS,  KC_MPLY,
                KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_TRNS,  KC_VOLD,  KC_VOLU,
                KC_TRNS,  KC_MUTE,
                KC_TRNS,  KC_TRNS
),
// TK LAYER
[TKTK] = LAYOUT_dactyl(
                       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                         RESET,  KC_TRNS,  KC_WH_U,  KC_MS_U,  KC_WH_D,  KC_TRNS,
                       KC_TRNS,  KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_TRNS,
                       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                              KC_TRNS,  KC_TRNS, DYN_MACRO_PLAY1, DYN_REC_START1,
                                                         KC_MPLY,   DYN_REC_STOP,
                                                         KC_MPRV,        KC_MNXT,
                       // right hand
                       RESET,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                       RESET,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,
                       KC_LEFT,  KC_DOWN,    KC_UP,  KC_RIGHT, KC_TRNS,  KC_MPLY,
                       KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                       DYN_REC_START2, DYN_MACRO_PLAY2,  KC_VOLD,  KC_VOLU,
                       DYN_REC_STOP,  KC_MUTE,
                       KC_TRNS,  KC_TRNS
                       ),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }

  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {};

#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // ensure these codes start after the highest keycode defined in Quantum
  VRSN,
  R_MAIL, // radio email
  G_MAIL, // google email
  R_ARR, // right arrow ->
  R_BARR, // right bold arrow =>
  TKL, // tehnoklistir
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Ins  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |; / L2| '    |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|Z/Ctrl|   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  |//Ctrl|RShift|
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |  ~/L1|'"/Alt|AltShf| Left | Right|                                  | Down |  Up  |   [  | ]/Alt| ~L1  |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |Esc/LG|Ralt/M|  |Ralt/M|Esc/RG|
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | Home |  | PgUp |      |      |
 *                               | Space|Backsp|------|  |------|  Tab |Enter |
 *                               |      |ace   | End  |  | PgDn |      |      |
 *                               `--------------------'  `--------------------'
  */
[BASE] = LAYOUT_dactyl(  // layer 0 : default
        // left hand
           KC_EQL,         KC_1,           KC_2,     KC_3,     KC_4,  KC_5,
          KC_DELT,         KC_Q,           KC_W,     KC_E,     KC_R,  KC_T,
          KC_INS,         KC_A,           KC_S,     KC_D,     KC_F,  KC_G,
          KC_LSPO,  CTL_T(KC_Z),           KC_X,     KC_C,     KC_V,  KC_B,
          LT(SYMB,KC_GRV),ALT_T(KC_QUOT),  LALT(KC_LSFT),KC_LEFT,KC_RGHT,
                                                                LGUI_T(KC_ESC), RALT_T(KC_APP),
                                                                                       KC_HOME,
                                                              KC_SPC,        KC_BSPC,   KC_END,
        // right hand
                             KC_6,   KC_7,     KC_8,     KC_9,               KC_0,         KC_MINS,
                             KC_Y,   KC_U,     KC_I,     KC_O,               KC_P,         KC_BSLS,
                             KC_H,   KC_J,     KC_K,     KC_L,  LT(MDIA, KC_SCLN),  GUI_T(KC_QUOT),
                             KC_N,   KC_M,  KC_COMM,   KC_DOT,     CTL_T(KC_SLSH),         KC_RSPC,
                             KC_DOWN,KC_UP,  KC_LBRC,            ALT_T(KC_RBRC),          KC_FN1,
           RALT_T(KC_APP),  RGUI_T(KC_ESC),
          KC_PGUP,
          KC_PGDN, KC_TAB, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |Versn |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ;  |   !  |   @  |   {  |   }  |   |  |                    |  Up  |   7  |   8  |   9  |   *  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   :  |   #  |   $  |   (  |   )  |   `  |                    | Down |   4  |   5  |   6  |   +  |   ,  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   %  |   ^  |   [  |   ]  |   ~  |                    |   &  |   1  |   2  |   3  |   /  |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |L1/RES|  ->  |  =>  |   <  |   >  |                                  |   -  |   .  |   0  |   =  |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      |   =  |  |  -   |      |      |
 *                               | Enter|      |------|  |------| BSpc | Space|
 *                               |      |      |   +  |  |  _   |      |      |
 *                               `--------------------'  `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_dactyl(
       // left hand
          VRSN,    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
       KC_SCLN,  KC_EXLM,    KC_AT,  KC_LCBR,  KC_RCBR,  KC_PIPE,
       KC_COLN,  KC_HASH,   KC_DLR,  KC_LPRN,  KC_RPRN,   KC_GRV,
       KC_TRNS,  KC_PERC,  KC_CIRC,  KC_LBRC,  KC_RBRC,  KC_TILD,
      MO(BASE),   R_ARR,   R_BARR,  KC_LT,  KC_GT,
                                                         KC_TRNS,  KC_TRNS,
                                                                   KC_EQL,
                                               KC_ENT,  KC_TRNS,  KC_PLUS,
       // right hand
                KC_F6,      KC_F7,   KC_F8, KC_F9,  KC_F10,   KC_F11,
                KC_UP,       KC_7,    KC_8,  KC_9, KC_ASTR,   KC_F12,
                KC_DOWN,     KC_4,    KC_5,  KC_6, KC_PLUS,  KC_COMM,
                KC_AMPR,     KC_1,    KC_2,  KC_3, KC_SLSH,  KC_TRNS,
                          KC_MINS,  KC_DOT,  KC_0,  KC_EQL,  KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_MINS,
      KC_UNDS,  KC_BSPC,  KC_SPC
),
/* Keymap 2: Media and mouse keys
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      | MsUp | Rmail|  tk  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | VolUp|MsLeft|MsDown|MsRght| Gmail|                    |      |      |      |      |      | Play |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | VolDn|      |      |      |      |                    |      |      | Prev | Next |      |      |
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |      | Mute |      | Lclk | Rclk |                                  | VolUp| VolDn| Mute |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      |      |      |  |      |      |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | Wh-U |  |      |      |Brwser|
 *                               | Lclk | Rclk |------|  |------|      |Back  |
 *                               |      |      | Wh-D |  |      |      |      |
 *                               `--------------------'  `--------------------'
 *
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_dactyl(
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_U,  R_MAIL,   TKL,
       KC_TRNS,  KC_VOLU,  KC_MS_L,  KC_MS_D,  KC_MS_R,  G_MAIL,
       KC_TRNS,  KC_VOLD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS,  KC_MUTE,  KC_TRNS,  KC_BTN1,  KC_BTN2,
                                                         KC_TRNS,  KC_TRNS,
                                                                   KC_WH_D,
                                               KC_BTN1,  KC_BTN2,  KC_WH_U,
    // right hand
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MPLY,
                KC_TRNS,  KC_TRNS,  KC_MPRV,  KC_MNXT,  KC_TRNS,  KC_TRNS,
                          KC_VOLU,  KC_VOLD,  KC_MUTE,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,
      KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_WBAK
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
  switch (keycode) {
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case R_MAIL:
      if (record->event.pressed) {
        SEND_STRING ("lio.novelli@radiostudent.si");
      }
      return false;
      break;
    case G_MAIL:
      if (record->event.pressed) {
        SEND_STRING ("liopolddoron@gmail.com");
      }
      return false;
      break;
    case R_ARR:
      if (record->event.pressed)  {
        SEND_STRING ("->");
      }
      return false;
      break;
    case R_BARR:
      if (record->event.pressed) {
        SEND_STRING ("=>");
      }
      return false;
      break;
    case TKL:
      if (record->event.pressed) {
        SEND_STRING ("tehnoklistir");
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

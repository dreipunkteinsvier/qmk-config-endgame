
#include QMK_KEYBOARD_H
#include <stdio.h>
#include <string.h>

enum layers {
    _QWERTY,
    _COLEMAK,
    _NAVIGATION,
    _MEDIA,
    _NUMBERS,
    _FUNCTION,
};

enum custom_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    OS_SWAP,
    MVWINR,
    MVWINL
};

// LEFT HAND HOME ROW MODS ├───────────────────────────────────┐
#define HM_A LGUI_T(KC_A)
#define HM_S LALT_T(KC_S)
#define HM_D LCTL_T(KC_D)
#define HM_F LSFT_T(KC_F)
#define HM_G RALT_T(KC_G)

// RIGHT HAND HOME ROW MODS ├──────────────────────────────────┐
#define HM_H RALT_T(KC_H)
#define HM_J RSFT_T(KC_J)
#define HM_K LCTL_T(KC_K)
#define HM_L LALT_T(KC_L)
#define HM_SCLN LGUI_T(KC_SCLN)

// CTRL + ARROWS ├─────────────────────────────────────────────┐
#define CT_LEFT LCTL(KC_LEFT)
#define CT_DOWN LCTL(KC_DOWN)
#define CT_UP LCTL(KC_UP)
#define CT_RGHT LCTL(KC_RGHT)

// THUMB KEY LAYER TAPS ├──────────────────────────────────────┐
#define TB_TAB LT(_MEDIA, KC_TAB)
#define TB_ENT LT(_NAVIGATION, KC_ENT)
#define TB_SPC LT(_NUMBERS, KC_SPC)
#define TB_BSPC LT(_FUNCTION, KC_BSPC)

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   c o m b o s                                 │
// └───────────────────────────────────────────────────────────┘
// vertical combos for umlauts
const uint16_t PROGMEM ae_combo[] = {KC_Q, HM_A, COMBO_END};
const uint16_t PROGMEM ss_combo[] = {KC_W, HM_S, COMBO_END};
const uint16_t PROGMEM ue_combo[] = {KC_U, HM_J, COMBO_END};
const uint16_t PROGMEM oe_combo[] = {KC_O, HM_L, COMBO_END};
// horizontal combos for mods
const uint16_t PROGMEM del_combo[] = {HM_H, HM_J, COMBO_END};
const uint16_t PROGMEM bsp_combo[] = {HM_J, HM_K, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {HM_K, HM_L, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {HM_F, HM_D, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {HM_D, HM_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(ae_combo, RALT(KC_Q)),
    COMBO(ss_combo, RALT(KC_S)),
    COMBO(ue_combo, RALT(KC_Y)),
    COMBO(oe_combo, RALT(KC_P)),
    COMBO(del_combo, KC_DEL),
    COMBO(bsp_combo, KC_BSPC),
    COMBO(ent_combo, KC_ENT),
    COMBO(tab_combo, KC_TAB),
    COMBO(esc_combo, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [_QWERTY] = LAYOUT_eg(
    KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,    KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,  
    HM_A,     HM_S,     HM_D,     HM_F,     HM_G,    HM_H,     HM_J,     HM_K,     HM_L,     HM_SCLN,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    KC_ESC,                       TB_TAB,   TB_ENT,  TB_SPC,   TB_BSPC,            KC_DEL
  ),

   [_COLEMAK] = LAYOUT_eg(
    KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,    KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,
    KC_A,     KC_R,     KC_S,     KC_T,     KC_D,    KC_H,     KC_N,     KC_E,     KC_I,     KC_O,
    KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_K,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
    KC_ESC,                       TB_TAB,   TB_ENT,  TB_SPC,   TB_BSPC,            KC_DEL
  ),

   [_NAVIGATION] = LAYOUT_eg(
    _______,  _______,  _______,  _______,  KC_LCBR,  KC_RCBR,  CT_LEFT,  CT_DOWN,    CT_UP,  CT_RGHT,
    KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_LPRN,  KC_RPRN,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,
    _______,  _______,  _______,  _______,  KC_LBRC,  KC_RBRC,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,
    _______,                      _______,  _______,  _______,  _______,                      _______
  ),

   [_MEDIA] = LAYOUT_eg(
    KC_UNDS,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI,
    KC_PLUS,  KC_DLR,   KC_PERC,  KC_CIRC,  KC_DQUO,  RGB_M_P,  RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD,
    KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_PIPE,  QWERTY,   COLEMAK,  _______,  _______,  QK_BOOTLOADER,
    _______,                      _______,  _______,  _______,  _______,                      _______
  ),

   [_NUMBERS] = LAYOUT_eg(
    KC_MINS,  KC_7,     KC_8,     KC_9,     KC_0,     _______,  KC_MPRV,  KC_VOLD,  KC_VOLU,  KC_MNXT,
    KC_EQL,   KC_4,     KC_5,     KC_6,     KC_QUOT,  KC_RALT,  KC_RSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_BSLS,  _______,  _______,  _______,  _______,  _______,
    _______,                      _______,  _______,  _______,  _______,                      _______
  ),

   [_FUNCTION] = LAYOUT_eg(
    KC_F12,   KC_F7,    KC_F8,    KC_F9,    KC_PSCR,  _______,  _______,  _______,  _______,  _______,
    KC_F11,   KC_F4,    KC_F5,    KC_F6,    _______,  KC_RALT,  KC_RSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,
    KC_F10,   KC_F1,    KC_F2,    KC_F3,    KC_INS,   _______,  _______,  _______,  _______,  _______,
    _______,                      _______,  _______,  _______,  _______,                      _______
  ),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // case SHT_T:
        //     return TAPPING_TERM - 150; // Recommended
        // case SHT_N:
        //     return TAPPING_TERM - 150; // Recommended
        default:
            return TAPPING_TERM;
    }
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_MINS:
    case KC_UNDS:
    case KC_LSFT:
    case KC_RSFT:
      return true;

    default:
      return false;  // Deactivate Caps Word.
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        case OS_SWAP: 
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(mac_song);
                  #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                  #ifdef AUDIO_ENABLE
                    PLAY_SONG(winxp_song);
                  #endif // AUDIO_ENABLE        
                }
              #ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
              #endif // HAPTIC_ENABLE
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys    
            return false;
          }
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;

      case MVWINR:
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_LSFT);
          tap_code(KC_RGHT);
        }
        break;

      case MVWINL:
        if (record->event.pressed) {
          register_code(KC_LGUI);
          register_code(KC_LSFT);
          tap_code(KC_LEFT);
        }
        break;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
        if (index == 0) {
             if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        } else if (index == 1) {
             if (clockwise) {
              tap_code(KC_PGDN);
          } else {
              tap_code(KC_PGUP);
          }
        }    
    return true;
}

#endif // ENCODER_ENABLE



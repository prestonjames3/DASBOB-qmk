#include QMK_KEYBOARD_H
// #include <stdio.h>

enum dasbob_layers {
  _DEFAULT,
  _ONE,
  _TWO,
  _THREE
};

enum custom_keycodes {
  SLSH_ASTR = SAFE_RANGE,
  ASTR_SLSH,
  PLOOPY,  // TOGGLE_PLOOPY_SCROLL
  ONEPASS,
  WRKPASS,
  CLEAR_ALL,
  F_PAINT,
  AFIT_COL,  // AUTOFIT_COL
  PASTE_VAL  // PASTE_VALUES
  // THEME_COLORS,
  // TAN_FILL,
  // GRAY_FILL,
  // OLIVE_FILL,
  // FREEZE_TOGGLE,
  // CLEAR_FILTERS
  // TD_CTL_QUOT_SCLN,   // MT(MOD_RCTL, KC_QUOT)   MT(MOD_RCTL, KC_SCLN)
  // TD_ALT_SLSH_BSLS   // MT(MOD_RALT, KC_SLSH)   MT(MOD_RALT, KC_BSLS)
  // TD_EQL_NOTEQL
};

enum td_keycodes {
  TD_CTL_QUOT_SCLN,   // MT(MOD_RCTL, KC_QUOT)   MT(MOD_RCTL, KC_SCLN)
  TD_ALT_SLSH_BSLS,   // MT(MOD_RALT, KC_SLSH)   MT(MOD_RALT, KC_BSLS)
  TD_CTL_TAB_CAPS,   // MT(MOD_LCTL, KC_TAB)   MT(MOD_LCTL, KC_CAPS)
  TD_ALT_GUI,
  TD_LSFT_TG3,
  TD_RSFT_TG3,
  TD_EQL_NOTEQL//,
  // TD_LGUI_EXLM
};

// Define a type containing as many tapdance states as you need
typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

// Create a global instance of the tapdance state type
// static td_state_t td_state;
typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

// Declare your tapdance functions:

// Function to determine the current tapdance state
td_state_t cur_dance(tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void ctl_quot_scln_finished(tap_dance_state_t *state, void *user_data);
void ctl_quot_scln_reset(tap_dance_state_t *state, void *user_data);
void alt_slsh_bsls_finished(tap_dance_state_t *state, void *user_data);
void alt_slsh_bsls_reset(tap_dance_state_t *state, void *user_data);
void ctl_tab_caps_finished(tap_dance_state_t *state, void *user_data);
void ctl_tab_caps_reset(tap_dance_state_t *state, void *user_data);
void alt_gui_finished(tap_dance_state_t *state, void *user_data);
void alt_gui_reset(tap_dance_state_t *state, void *user_data);
void lsft_tg3_finished(tap_dance_state_t *state, void *user_data);
void lsft_tg3_reset(tap_dance_state_t *state, void *user_data);
void rsft_tg3_finished(tap_dance_state_t *state, void *user_data);
void rsft_tg3_reset(tap_dance_state_t *state, void *user_data);
void eql_noteql_finished(tap_dance_state_t *state, void *user_data);
void eql_noteql_reset(tap_dance_state_t *state, void *user_data);
// void lgui_exlm_finished(tap_dance_state_t *state, void *user_data);
// void lgui_exlm_reset(tap_dance_state_t *state, void *user_data);



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │DEL├───┐           ┌───┤ESC│
      *           └───┤SPC├───┐   ┌───┤BSP├───┘
      *               └───│LOW│   │RSE├───┘
      *                   └───┘   └───┘
      */


  [_DEFAULT] = LAYOUT_split_3x5_3(
                //,-------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
                            MT(MOD_LGUI, KC_Q),    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    MT(MOD_RGUI, KC_P),
                //|--------+----------------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------------------+--------|
                            MT(MOD_LCTL, KC_A),    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,  TD(TD_CTL_QUOT_SCLN),
                //|--------+----------------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------------------+--------|
                            MT(MOD_LALT, KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M, KC_COMM,  KC_DOT,  TD(TD_ALT_SLSH_BSLS),
                //|--------+----------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+----------------------+--------|
              LT(2, KC_ENT),               LT(1, KC_BSPC),                MT(MOD_LSFT, KC_SPC),    MT(MOD_RSFT, KC_SPC),                LT(1, KC_BSPC),               LT(2, KC_ENT)
          // LT(2, KC_BSPC),                LT(1, KC_ENT),                MT(MOD_LSFT, KC_SPC),    MT(MOD_RSFT, KC_SPC),                LT(1, KC_ENT),                LT(2, KC_BSPC)
                   // MO(2),                        MO(1),                MT(MOD_LSFT, KC_SPC),    MT(MOD_RSFT, KC_SPC),                MO(1),                        MO(2)
                         //              _______,               _______,               _______,    _______,               _______,               _______
                         //----------------------+----------------------+----------------------'  `----------------------+----------------------+----------------------
                                                    //`----------------------------------------'  `----------------------------------------'
  ),

  [_ONE] = LAYOUT_split_3x5_3(
                //,-------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
                            MT(MOD_LGUI, KC_1),    KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    MT(MOD_RGUI, KC_0),
                //|--------+----------------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------------------+--------|
                            TD(TD_CTL_TAB_CAPS),   KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,                       XXXXXXX, KC_BTN1, KC_BTN2,  PLOOPY,  MT(MOD_RCTL, KC_DQT),
                //|--------+----------------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------------------+--------|
                            KC_LALT,               C(KC_X), C(KC_C), C(KC_V), C(KC_SLSH),                A(S(KC_B)), C(KC_V), C(KC_C), C(KC_X), MT(MOD_RALT, KC_QUES),
                //|--------+----------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+----------------------+--------|
                             TG(3),               _______,                MT(MOD_LSFT, KC_ENT),    MT(MOD_RSFT, KC_BSPC),               _______,               TG(3)
                          // TG(3),               _______,                MT(MOD_LSFT, KC_ENT),    MT(MOD_RSFT, KC_ENT),                _______,               TG(3)
                         //              _______,               _______,               _______,    _______,               _______,               _______
                         //----------------------+----------------------+----------------------'  `----------------------+----------------------+----------------------
                                                    //`----------------------------------------'  `----------------------------------------'
  ),

  [_TWO] = LAYOUT_split_3x5_3(
                //,-------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
                            MT(MOD_LGUI, KC_1),    KC_AT,   KC_HASH, KC_DLR,  SLSH_ASTR,                  ASTR_SLSH, KC_PERC, KC_CIRC, KC_AMPR,               KC_ASTR,
                // XXXXXXX, KC_ESC,                KC_GRV,  XXXXXXX, AFIT_COL, KC_LBRC,                     KC_RBRC, KC_PGUP, KC_PGDN, KC_MINS,                KC_EQL, _______,
                //|--------+----------------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------------------+--------|
                            MT(MOD_LCTL, KC_ESC),  KC_GRV,  C(KC_Z), C(A(KC_TAB)), KC_LPRN,                 KC_RPRN, KC_LEFT,   KC_UP, KC_DOWN,               KC_RGHT,
                //|--------+----------------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------------------+--------|
                            TD(TD_ALT_GUI),        XXXXXXX, C(KC_Y), KC_F2,   KC_LBRC,                      KC_RBRC, KC_PGUP, KC_PGDN, KC_WH_U,               KC_WH_D,
                // _______, KC_LALT,               KC_LGUI, XXXXXXX, C(KC_SLSH), SLSH_ASTR,               ASTR_SLSH, KC_WH_L, KC_WH_U, KC_WH_D,               KC_WH_R, _______,
                //|--------+----------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+----------------------+--------|
                     _______,                 TG(3),                      MT(MOD_LSFT, KC_ENT),    MT(MOD_RSFT, KC_BSPC),                     TG(3),                 _______
                //// _______,                 TG(3),                MT(MOD_LSFT, LSFT(KC_ENT)),    MT(MOD_RSFT, RSFT(KC_BSPC)),               TG(3),                 _______
                  // _______,                 TG(3),                      MT(MOD_LSFT, KC_ENT),    MT(MOD_RSFT, KC_ENT),                      TG(3),                 _______
                         //              _______,               _______,               _______,    _______,               _______,               _______
                         //----------------------+----------------------+----------------------'  `----------------------+----------------------+----------------------
                                                    //`----------------------------------------'  `----------------------------------------'
  ),

  [_THREE] = LAYOUT_split_3x5_3(
                //,-------------------------------------------------------------------.                    ,-------------------------------------------------------------------.
                            MT(MOD_LGUI, KC_F1),   KC_F2,   KC_F3,   KC_F4,   KC_F5,                          KC_F6,   KC_F7,   KC_F8,   KC_F9,  MT(MOD_RGUI, KC_F10),
                //|--------+----------------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------------------+--------|
                            MT(MOD_LCTL, KC_F11),  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               KC_RCTL,
                //|--------+----------------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+----------------------+--------|
                // XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, ONEPASS, WRKPASS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX,
                            KC_LALT,               XXXXXXX, XXXXXXX, ONEPASS, WRKPASS,                      DT_PRNT,   DT_UP, DT_DOWN, XXXXXXX,               KC_RALT,
                //|--------+----------------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+----------------------+--------|
                                         _______,               _______,       TD(TD_LSFT_TG3),    TD(TD_RSFT_TG3),       _______,               _______
                         //              _______,               _______,               _______,    _______,               _______,               _______
                         //----------------------+----------------------+----------------------'  `----------------------+----------------------+----------------------
                                                    //`----------------------------------------'  `----------------------------------------'
  )
};



#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_0; }
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        static const char PROGMEM runqmk_logo[] = {0,0,0,0,152,152,152,152,152,152,24,24,24,
        152,152,24,24,24,152,152,24,24,152,152,24,24,24,152,152,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,127,127,13,13,29,63,103,64,0,63,127,96,96,96,127,63,0,0,127,127,7,12,56,
        127,127,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,120,252,134,198,198,252,120,0,0,254,254,
        60,224,224,60,254,254,0,254,254,16,24,124,230,130,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,24,24,25,25,25,25,27,24,24,25,25,24,25,25,24,25,25,24,25,25,24,24,24,24,25,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0};


        oled_write_raw_P(runqmk_logo, sizeof(runqmk_logo));

        led_t led_usb_state = host_keyboard_led_state();
        oled_set_cursor(6, 3);
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUM") : PSTR(""), false);
        oled_set_cursor(6, 2);
        oled_write_P(PSTR("WPM: "), false);
        oled_write(get_u8_str(get_current_wpm(), '0'), false);
        oled_set_cursor(6, 0);
        oled_write_P(PSTR("by GroooveBob"), false);
            oled_set_cursor(6, 1);
            oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _DEFAULT:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _ONE:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("One\n"), false);
            break;
        case _TWO:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Two\n"), false);
            break;
        case _THREE:
        oled_set_cursor(12, 1);
            oled_write_P(PSTR("Three\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
        oled_set_cursor(6, 1);
        oled_write_ln_P(PSTR("Undefined"), false);
    }
    } else {
        static const char PROGMEM dasbob_logo[] = {
        0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,128,128,128,192,192,192,192,192,192,192,192,192,192,192,128,128,  0,  0,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,  0,128,128,128,128,128,192,192,192,192,192,  0,  0,  0,128,128,128,128,128,128,128,128,128,  0,  0,  0,  0,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,128,  0,  0,
        0,  0,126,127,255,255,255,255,255,255,255,199,247,255,255,255,255,255,255,255,255,127,252,255,255,255,255,255,255,255,255,255, 15,127,255,255,255,255,255,255,255,255,254,248,  0,126,127,255,255,255,255,255,255,255,199,247,255,255,255,255,255,255,255,255,127,126,255,255,255,255,255,255,255,255,239,239,239,239,207,223,223,223,159, 63,  0,  7, 63,255,255,255,255,255,255,255,254, 14,254,255,255,255,255,255,255,255, 63,241,252,254,255,255,255,255,255,255,255, 31,255,255,255,255,255,255,255,255,255,255,128,  0,
        0,  0,126,255,255,255,255,255,255,255,255,227,255,255,255,255,255,255,255,255,255,  0, 15, 63,127,255,255,255,255,255,255,255,248,255,255,255,255,255,255,255,255,127, 63,  7,  0,126,255,255,255,255,255,255,255,255,227,255,255,255,255,255,255,255,255,255,128,252,253,249,249,251,251,251,251,251,255,255,255,255,255,255,255,255,127, 30,  0,  0,  0,  3, 31,255,255,255,255,255,255,255,255,255,255,255,255,255,255,  7,  0, 63,255,255,255,255,255,255,255,255,255,248,255,255,255,255,255,255,255,255,255,255,255,  0,
        0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,
        };
        oled_write_raw_P(dasbob_logo, sizeof(dasbob_logo));
    }
    return false;
}
#endif // OLED_ENABLE



// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // Store the current modifier state in the variable for later reference
  mod_state = get_mods();

//   if (record->event.pressed) {
//     #ifdef OLED_DRIVER_ENABLE
//       set_keylog(keycode, record);
//     #endif // OLED_DRIVER_ENABLE
//   }
//   //return true;

  switch (keycode) {

    case SLSH_ASTR:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING( "/*" );
      //} else {
        // when keycode is released
      }
      break;

    case ASTR_SLSH:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING( "*/" );
      //} else {
        // when keycode is released
      }
      break;

    case PLOOPY:  // TOGGLE_PLOOPY_SCROLL
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING( SS_TAP(X_NUM) SS_TAP(X_NUM) );
      //} else {
        // when keycode is released
      }
      break;

    case ONEPASS:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING( "xxxxxxx01" );
      //} else {
        // when keycode is released
      }
      break;

    case WRKPASS:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING( "xxxxxxx02" );
      //} else {
        // when keycode is released
      }
      break;

    case CLEAR_ALL:
      if (record->event.pressed) {
        // when keycode is pressed
        // SEND_STRING( SS_LALT("hea") );
        SEND_STRING( SS_TAP(X_LALT) "hea" );
      //} else {
        // when keycode is released
      }
      break;

    case F_PAINT:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING( SS_TAP(X_LALT) "hfp" );
      //} else {
        // when keycode is released
      }
      break;

    case AFIT_COL:  // AUTOFIT_COL
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING( SS_TAP(X_LALT) "hoi" );
      //} else {
        // when keycode is released
      }
      break;

    case PASTE_VAL:  // PASTE_VALUES
      if(record->event.pressed) {
        register_code(KC_LCTL);
        register_code(KC_LALT);
        register_code(KC_V);
      } else {
        unregister_code(KC_V);
        unregister_code(KC_LALT);
        unregister_code(KC_LCTL);
        tap_code(KC_DOWN);
        tap_code(KC_DOWN);
        tap_code(KC_ENT);
      }
      return false;

    // case THEME_COLORS:
    //   if (record->event.pressed) {
    //     // when keycode is pressed
    //     SEND_STRING( SS_TAP(X_LALT) "ptc" SS_TAP(X_DOWN) SS_TAP(X_ENT) SS_TAP(X_LALT) "h" SS_TAP(X_LALT) );
    //   //} else {
    //     // when keycode is released
    //   }
    //   break;

    // case TAN_FILL:
    //   if (record->event.pressed) {
    //     // when keycode is pressed
    //     SEND_STRING( SS_TAP(X_LALT) "hh" SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_DOWN) SS_TAP(X_ENT) );
    //   //} else {
    //     // when keycode is released
    //   }
    //   break;

    // case GRAY_FILL:
    //   if (record->event.pressed) {
    //     // when keycode is pressed
    //     SEND_STRING( SS_TAP(X_LALT) "hh" SS_TAP(X_DOWN) SS_TAP(X_DOWN) SS_TAP(X_ENT) );
    //   //} else {
    //     // when keycode is released
    //   }
    //   break;

    // case OLIVE_FILL:
    //   if (record->event.pressed) {
    //     // when keycode is pressed
    //     SEND_STRING( SS_TAP(X_LALT) "hh" SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_RGHT) SS_TAP(X_DOWN) SS_TAP(X_ENT) );
    //   //} else {
    //     // when keycode is released
    //   }
    //   break;

    // case FREEZE_TOGGLE:
    //   if (record->event.pressed) {
    //     // when keycode is pressed
    //     SEND_STRING( SS_TAP(X_LALT) "wff" SS_TAP(X_LALT) "h" SS_TAP(X_LALT) );
    //   //} else {
    //     // when keycode is released
    //   }
    //   break;

    // case CLEAR_FILTERS:
    //   if (record->event.pressed) {
    //     // when keycode is pressed
    //     SEND_STRING( SS_TAP(X_LALT) "ac" SS_TAP(X_LALT) "h" SS_TAP(X_LALT) );
    //   //} else {
    //     // when keycode is released
    //   }
    //   break;


    case KC_BSPC:
      {
      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool delkey_registered;
      if (record->event.pressed) {
        // Detect the activation of either shift keys
        if (mod_state & MOD_MASK_SHIFT) {
          // First temporarily canceling both shifts so that
          // shift isn't applied to the KC_DEL keycode
          del_mods(MOD_MASK_SHIFT);
          register_code(KC_DEL);
          // Update the boolean variable to reflect the status of KC_DEL
          delkey_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
      } else { // on release of KC_BSPC
        // In case KC_DEL is still being sent even after the release of KC_BSPC
        if (delkey_registered) {
          unregister_code(KC_DEL);
          delkey_registered = false;
          return false;
        }
      }
      // Let QMK process the KC_BSPC keycode as usual outside of shift
      return true;
      }
      break;  //?????


    case KC_LPRN:
      {
      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool labk_registered;
      if (record->event.pressed) {
        // Detect the activation of either shift keys
        if (mod_state & MOD_MASK_SHIFT) {
          // First temporarily canceling both shifts so that
          // shift isn't applied to the KC_LABK keycode
          del_mods(MOD_MASK_SHIFT);
          register_code16(KC_LABK);
          // Update the boolean variable to reflect the status of KC_LABK
          labk_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
      } else { // on release of KC_LPRN
        // In case KC_LABK is still being sent even after the release of KC_LPRN
        if (labk_registered) {
          unregister_code16(KC_LABK);
          labk_registered = false;
          return false;
        }
      }
      // Let QMK process the KC_LPRN keycode as usual outside of shift
      return true;
      }
      break;  //?????

    case KC_RPRN:
      {
      // Initialize a boolean variable that keeps track
      // of the delete key status: registered or not?
      static bool rabk_registered;
      if (record->event.pressed) {
        // Detect the activation of either shift keys
        if (mod_state & MOD_MASK_SHIFT) {
          // First temporarily canceling both shifts so that
          // shift isn't applied to the KC_RABK keycode
          del_mods(MOD_MASK_SHIFT);
          register_code16(KC_RABK);
          // Update the boolean variable to reflect the status of KC_RABK
          rabk_registered = true;
          // Reapplying modifier state so that the held shift key(s)
          // still work even after having tapped the Backspace/Delete key.
          set_mods(mod_state);
          return false;
        }
      } else { // on release of KC_RPRN
        // In case KC_RABK is still being sent even after the release of KC_RPRN
        if (rabk_registered) {
          unregister_code16(KC_RABK);
          rabk_registered = false;
          return false;
        }
      }
      // Let QMK process the KC_RPRN keycode as usual outside of shift
      return true;
      }
      break;  //?????



    case LT(2, KC_BSPC):
      if (record->tap.count && record->event.pressed) {


        //// tap_code16(KC_DQUO); // Send KC_DQUO on tap
        // tap_code16(RSFT(KC_BSPC));


      // //// case KC_BSPC:
      //   {
      //   // Initialize a boolean variable that keeps track
      //   // of the delete key status: registered or not?
      //   static bool delkey_registered;
      //   if (record->event.pressed) {
      //     // Detect the activation of either shift keys
      //     if (mod_state & MOD_MASK_SHIFT) {
      //       // First temporarily canceling both shifts so that
      //       // shift isn't applied to the KC_DEL keycode
      //       del_mods(MOD_MASK_SHIFT);
      //       register_code(KC_DEL);
      //       // Update the boolean variable to reflect the status of KC_DEL
      //       delkey_registered = true;
      //       // Reapplying modifier state so that the held shift key(s)
      //       // still work even after having tapped the Backspace/Delete key.
      //       set_mods(mod_state);
      //       return false;
      //     }
      //   } else { // on release of KC_BSPC
      //     // In case KC_DEL is still being sent even after the release of KC_BSPC
      //     if (delkey_registered) {
      //       unregister_code(KC_DEL);
      //       delkey_registered = false;
      //       return false;
      //     }
      //   }
      //   // Let QMK process the KC_BSPC keycode as usual outside of shift
      //   return true;//tap_code16(KC_BSPC);  // NOTE: both of these seem to work
      //   }

      //// case KC_BSPC:
        {
        // Initialize a boolean variable that keeps track
        // of the delete key status: registered or not?
        /// static bool delkey_registered;
        if (record->event.pressed) {
          // Detect the activation of either shift keys
          if (mod_state & MOD_MASK_SHIFT) {
            // First temporarily canceling both shifts so that
            // shift isn't applied to the KC_DEL keycode
            del_mods(MOD_MASK_SHIFT);
            /// register_code(KC_DEL);
            tap_code16(KC_DEL);
            // Update the boolean variable to reflect the status of KC_DEL
            /// delkey_registered = true;
            // Reapplying modifier state so that the held shift key(s)
            // still work even after having tapped the Backspace/Delete key.
            set_mods(mod_state);
            return false;
          }
        /// } else { // on release of KC_BSPC
        ///   // In case KC_DEL is still being sent even after the release of KC_BSPC
        ///   if (delkey_registered) {
        ///     unregister_code(KC_DEL);
        ///     delkey_registered = false;
        ///     return false;
        ///   }
        }
        // Let QMK process the KC_BSPC keycode as usual outside of shift
        return true;//tap_code16(KC_BSPC);  // NOTE: ?both of these seem to work?
        }


        return false;        // Return false to ignore further processing of key
      }
      break;

    // case MT(MOD_LSFT, LSFT(KC_ENT)):  //// LCTL_T(KC_DQUO):
    case MT(MOD_LSFT, KC_ENT):  //// LCTL_T(KC_DQUO):
      if (record->tap.count && record->event.pressed) {
        //// tap_code16(KC_DQUO); // Send KC_DQUO on tap
        // tap_code16(LSFT(KC_ENT));  // This function works similar to its regular counterpart, but allows you to use modded keycodes (with Shift, Alt, Control, and/or GUI applied to them).
        if      (IS_LAYER_ON(2)) {
          tap_code16(LSFT(KC_ENT));  // This function works similar to its regular counterpart, but allows you to use modded keycodes (with Shift, Alt, Control, and/or GUI applied to them).
        } else {
          tap_code16(KC_ENT);  // This function works similar to its regular counterpart, but allows you to use modded keycodes (with Shift, Alt, Control, and/or GUI applied to them).
        }
        return false;        // Return false to ignore further processing of key
      }
      break;

    // case MT(MOD_RSFT, RSFT(KC_BSPC)):  //// LCTL_T(KC_DQUO):
    case MT(MOD_RSFT, KC_BSPC):  //// LCTL_T(KC_DQUO):
      if (record->tap.count && record->event.pressed) {
        //// tap_code16(KC_DQUO); // Send KC_DQUO on tap
        // tap_code16(RSFT(KC_BSPC));
        if      (IS_LAYER_ON(2)) {
          // tap_code16(RSFT(KC_BSPC));
          tap_code16(KC_DEL);
        } else {
          tap_code16(KC_BSPC);
        }
        return false;        // Return false to ignore further processing of key
      }
      break;

    // case MT(MOD_LGUI, KC_EXLM):
    // case MT(MOD_RSFT, RSFT(KC_1)):
    case MT(MOD_LGUI, KC_1):
      if (record->tap.count && record->event.pressed) {
        if      (IS_LAYER_ON(2)) {
          tap_code16(RSFT(KC_1));
        } else {
          tap_code16(KC_1);
        }
        return false;        // Return false to ignore further processing of key
      }
      break;


  }
  // We return true to indicate to the caller that the key press we just processed should continue to be processed as normal
  // (as we didn’t replace or alter the functionality).
  return true;
}



// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case MT(MOD_LCTL, KC_A):
//             return false;  // Do not select the hold action when another key is pressed.
//         case MT(MOD_LCTL, KC_ESC):
//             return false;
//         case MT(MOD_LCTL, KC_F11):
//             return false;
//         case MT(MOD_RCTL, KC_SCLN):
//             return false;
//         case MT(MOD_RGUI, KC_SLSH):
//             return false;
//         case MT(MOD_LALT, KC_Z):
//             return false;

//         // TD(TD_CTL_QUOT_SCLN)
//         // TD(TD_CTL_TAB_CAPS)
//         // TD(TD_ALT_GUI)
//         // TD(TD_ALT_SLSH_BSLS)

//         default:
//             return true;  // Immediately select the hold action when another key is pressed.

//         // LT(1, KC_BSPC)
//         // LT(2, KC_ENT)
//         // MT(MOD_LSFT, KC_SPC)
//         // MT(MOD_LSFT, KC_ENT)
//         // MT(MOD_RSFT, KC_SPC)
//         // MT(MOD_RSFT, KC_BSPC)
//         // MT(MOD_LSFT, LSFT(KC_ENT))
//         // MT(MOD_RSFT, RSFT(KC_BSPC))

//         // TD(TD_LSFT_TG3)
//         // TD(TD_RSFT_TG3)
//     }
// }

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LGUI, KC_Q):
            return false;  // Do not select the hold action when another key is pressed.
        case MT(MOD_RGUI, KC_P):
            return false;
        case MT(MOD_LCTL, KC_A):
            return false;
        // TD(TD_CTL_QUOT_SCLN)
        case MT(MOD_LALT, KC_Z):
            return false;
        // TD(TD_ALT_SLSH_BSLS)


        case MT(MOD_LGUI, KC_1):  //***************
            return false;
        case MT(MOD_RGUI, KC_0):
            return false;
        // TD(TD_CTL_TAB_CAPS)
        case MT(MOD_RCTL, KC_DQT):
            return false;
        case MT(MOD_RALT, KC_QUES):
            return false;


        /// case MT(MOD_LGUI, KC_EXLM):  //******************************
        ///     return false;
        //// TD(TD_LGUI_EXLM)
        case MT(MOD_LCTL, KC_ESC):
            return false;
        // TD(TD_ALT_GUI)


        case MT(MOD_LGUI, KC_F1):
            return false;
        case MT(MOD_RGUI, KC_F10):
            return false;
        case MT(MOD_LCTL, KC_F11):
            return false;


        default:
            return true;  // Immediately select the hold action when another key is pressed.

        // LT(2, KC_ENT)  //xxx
        // LT(1, KC_BSPC)  //xxx
        // MT(MOD_LSFT, KC_SPC)  //xxx
        // MT(MOD_RSFT, KC_SPC)  //xxx


        // MT(MOD_LSFT, KC_ENT)  //xxx
        // MT(MOD_RSFT, KC_BSPC)  //xxx


        // MT(MOD_LSFT, KC_ENT)  //xxx
        // MT(MOD_RSFT, KC_BSPC)  //xxx


        // TD(TD_LSFT_TG3)
        // TD(TD_RSFT_TG3)
    }
}



//// bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_SPC):
            return 0;////true;
        case MT(MOD_RSFT, KC_SPC):
            return 0;////true;
        case MT(MOD_LSFT, KC_ENT):
            return 0;////true;
        case MT(MOD_RSFT, KC_BSPC):
            return 0;////true;
        // case MT(MOD_LSFT, LSFT(KC_ENT)):
        //     return 0;////true;
        // case MT(MOD_RSFT, RSFT(KC_BSPC)):
        //     return 0;////true;
        default:
            return QUICK_TAP_TERM;////false;
    }
}



// Determine the tapdance state to return
// td_state_t cur_dance(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
//         else return TD_SINGLE_HOLD;
//     }

//     if (state->count == 2) return TD_DOUBLE_SINGLE_TAP;
//     else return TD_UNKNOWN; // Any number higher than the maximum state value you return above
// }
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed) return TD_DOUBLE_HOLD;
        else return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
        else return TD_TRIPLE_HOLD;
    } else return TD_UNKNOWN;
}
// td_state_t cur_dance(tap_dance_state_t *state) {
//     if (state->count == 1) {
//         if (state->interrupted || state->pressed) return TD_SINGLE_HOLD;
//         // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
//         else return TD_SINGLE_TAP;
//     } else if (state->count == 2) {
//         // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
//         // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
//         // keystrokes of the key, and not the 'double tap' action/macro.
//         if (state->interrupted || state->pressed) return TD_DOUBLE_HOLD;
//         // if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
//         // else if (state->pressed) return TD_DOUBLE_HOLD;
//         else return TD_DOUBLE_TAP;
//     }

//     // Assumes no one is trying to type the same letter three times (at least not quickly).
//     // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
//     // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
//     if (state->count == 3) {
//         if (state->interrupted || state->pressed) return TD_TRIPLE_HOLD;
//         else return TD_TRIPLE_TAP;
//     } else return TD_UNKNOWN;
// }

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};


// Handle the possible states for each tapdance keycode you define:

void ctl_quot_scln_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_QUOT); break;
        case TD_SINGLE_HOLD: register_code(KC_RCTL); break;
        // case TD_SINGLE_HOLD:
        //     register_mods(MOD_BIT(KC_RCTL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_TAP: register_code(KC_SCLN); break;
        // case TD_DOUBLE_HOLD: register_code(KC_RALT); break;
        // case TD_DOUBLE_HOLD:
        //     register_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // In order to type `xx` when typing fast, the next character will have to be hit within the `TAPPING_TERM`.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_QUOT); register_code(KC_QUOT); break;
        default: break;
    }
}
void ctl_quot_scln_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_QUOT); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RCTL); break;
        // case TD_SINGLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_RCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_TAP: unregister_code(KC_SCLN); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_RALT); break;
        // case TD_DOUBLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_QUOT); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void alt_slsh_bsls_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_SLSH); break;
        case TD_SINGLE_HOLD: register_code(KC_RALT); break;
        // case TD_SINGLE_HOLD:
        //     register_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_TAP: register_code(KC_BSLS); break;
        // case TD_DOUBLE_HOLD: register_code(KC_RALT); break;
        // case TD_DOUBLE_HOLD:
        //     register_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // In order to type `xx` when typing fast, the next character will have to be hit within the `TAPPING_TERM`.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_SLSH); register_code(KC_SLSH); break;
        default: break;
    }
}
void alt_slsh_bsls_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_SLSH); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RALT); break;
        // case TD_SINGLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_TAP: unregister_code(KC_BSLS); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_RALT); break;
        // case TD_DOUBLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_RALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_SLSH); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void ctl_tab_caps_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_TAB); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        // case TD_SINGLE_HOLD:
        //     register_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_TAP: register_code(KC_CAPS); break;
        // case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // case TD_DOUBLE_HOLD:
        //     register_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // In order to type `xx` when typing fast, the next character will have to be hit within the `TAPPING_TERM`.
        case TD_DOUBLE_SINGLE_TAP: tap_code(KC_TAB); register_code(KC_TAB); break;
        default: break;
    }
}
void ctl_tab_caps_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_TAB); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        // case TD_SINGLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_LCTL)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_TAP: unregister_code(KC_CAPS); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        // case TD_DOUBLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_TAB); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void alt_gui_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        // case TD_SINGLE_TAP: register_code(KC_X); break;
        case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        // case TD_SINGLE_HOLD:
        //     register_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_TAP: register_code(KC_Y); break;
        case TD_DOUBLE_HOLD: register_code(KC_LGUI); break;
        // case TD_DOUBLE_HOLD:
        //     register_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // In order to type `xx` when typing fast, the next character will have to be hit within the `TAPPING_TERM`.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        default: break;
    }
}
void alt_gui_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        // case TD_SINGLE_TAP: unregister_code(KC_X); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        // case TD_SINGLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_TAP: unregister_code(KC_Y); break;
        case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); break;
        // case TD_DOUBLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void lsft_tg3_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: layer_on(3); break;
        case TD_SINGLE_HOLD: register_code(KC_LSFT); break;
        // case TD_SINGLE_HOLD:
        //     register_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_TAP: register_code(KC_Y); break;
        // case TD_DOUBLE_HOLD: register_code(KC_LGUI); break;
        // case TD_DOUBLE_HOLD:
        //     register_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // In order to type `xx` when typing fast, the next character will have to be hit within the `TAPPING_TERM`.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        default: break;
    }
}
void lsft_tg3_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: layer_off(3); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LSFT); break;
        // case TD_SINGLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_TAP: unregister_code(KC_Y); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); break;
        // case TD_DOUBLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void rsft_tg3_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: layer_on(3); break;
        case TD_SINGLE_HOLD: register_code(KC_RSFT); break;
        // case TD_SINGLE_HOLD:
        //     register_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_TAP: register_code(KC_Y); break;
        // case TD_DOUBLE_HOLD: register_code(KC_LGUI); break;
        // case TD_DOUBLE_HOLD:
        //     register_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // In order to type `xx` when typing fast, the next character will have to be hit within the `TAPPING_TERM`.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        default: break;
    }
}
void rsft_tg3_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: layer_off(3); break;
        case TD_SINGLE_HOLD: unregister_code(KC_RSFT); break;
        // case TD_SINGLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_TAP: unregister_code(KC_Y); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); break;
        // case TD_DOUBLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void eql_noteql_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code(KC_EQL); break;
        // case TD_SINGLE_HOLD: register_code(KC_LALT); break;
        // case TD_SINGLE_HOLD:
        //     register_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_TAP: register_code16(KC_EXLM); register_code(KC_EQL); break;
        // case TD_DOUBLE_HOLD: register_code(KC_LGUI); break;
        // case TD_DOUBLE_HOLD:
        //     register_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
        //     break;
        // In order to type `xx` when typing fast, the next character will have to be hit within the `TAPPING_TERM`.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        default: break;
    }
}
void eql_noteql_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code(KC_EQL); break;
        // case TD_SINGLE_HOLD: unregister_code(KC_LALT); break;
        // case TD_SINGLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        case TD_DOUBLE_TAP: unregister_code16(KC_EXLM); unregister_code(KC_EQL); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); break;
        // case TD_DOUBLE_HOLD:
        //     unregister_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
        //     break;
        // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

// void lgui_exlm_finished(tap_dance_state_t *state, void *user_data) {
//     xtap_state.state = cur_dance(state);
//     switch (xtap_state.state) {
//         case TD_SINGLE_TAP: register_code(KC_RSFT); register_code(KC_1); break;
//         case TD_SINGLE_HOLD: register_code(KC_LGUI); break;
//         // case TD_SINGLE_HOLD:
//         //     register_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
//         //     break;
//         // case TD_DOUBLE_TAP: register_code16(KC_EXLM); register_code(KC_EQL); break;
//         // case TD_DOUBLE_HOLD: register_code(KC_LGUI); break;
//         // case TD_DOUBLE_HOLD:
//         //     register_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_on(_MY_LAYER)` here
//         //     break;
//         // In order to type `xx` when typing fast, the next character will have to be hit within the `TAPPING_TERM`.
//         // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
//         default: break;
//     }
// }
// void lgui_exlm_reset(tap_dance_state_t *state, void *user_data) {
//     switch (xtap_state.state) {
//         case TD_SINGLE_TAP: unregister_code(KC_1); unregister_code(KC_RSFT); break;
//         case TD_SINGLE_HOLD: unregister_code(KC_LGUI); break;
//         // case TD_SINGLE_HOLD:
//         //     unregister_mods(MOD_BIT(KC_lALT)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
//         //     break;
//         // case TD_DOUBLE_TAP: unregister_code16(KC_EXLM); unregister_code(KC_EQL); break;
//         // case TD_DOUBLE_HOLD: unregister_code(KC_LGUI); break;
//         // case TD_DOUBLE_HOLD:
//         //     unregister_mods(MOD_BIT(KC_lGUI)); // For a layer-tap key, use `layer_off(_MY_LAYER)` here
//         //     break;
//         // case TD_DOUBLE_SINGLE_TAP: unregister_code(KC_X); break;
//         default: break;
//     }
//     xtap_state.state = TD_NONE;
// }


// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
tap_dance_action_t tap_dance_actions[] = {
    [TD_CTL_QUOT_SCLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_quot_scln_finished, ctl_quot_scln_reset),
    [TD_ALT_SLSH_BSLS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_slsh_bsls_finished, alt_slsh_bsls_reset),
    [TD_CTL_TAB_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ctl_tab_caps_finished, ctl_tab_caps_reset),
    [TD_ALT_GUI] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, alt_gui_finished, alt_gui_reset),
    [TD_LSFT_TG3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_tg3_finished, lsft_tg3_reset),
    [TD_RSFT_TG3] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rsft_tg3_finished, rsft_tg3_reset),
    [TD_EQL_NOTEQL] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, eql_noteql_finished, eql_noteql_reset)
};

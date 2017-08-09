// AVR
#include <util/delay.h>

#include "keymap_common.h"
#include "keymap_phatina_functions.c"
#include "command.h"
#include "bootloader.h"
#include "action_layer.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP(   // LAYER 0: Default
      FN13, 1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  GRV,  BSLS,\
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSPC,      \
      FN30, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   DEL, \
      RCTL, LGUI,  LALT, FN2,             SPC,              FN3,  FN1, MENU, LEFT, DOWN,  RGHT,\
      NO,  NO                                                                                \
    ),
    KEYMAP(   // LAYER 1
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, VOLD, VOLU,\
      TRNS, FN21, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,      \
      CAPS, TRNS, FN20, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       FN17,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, FN16,\
      TRNS, TRNS, TRNS, TRNS,             TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
      TRNS, TRNS                                                                               \
    ),
    KEYMAP(   // LAYER 2
      TRNS, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  VOLD, VOLU, \
      TRNS, NO,   UP,   NO,   NO,   NO,   NO,   NO,    NO,  NO,   NO,   NO,   NO,   NO,         \
      TRNS, LEFT, DOWN, RIGHT,NO,   NO,   NO,   INS,  HOME, PGUP, BSPC, NO,         NO,         \
      TRNS, NO,   NO,   NO,   NO,   NO,   NO,   DEL,  END,  PGDN, NO,         TRNS, MSTP, NO,   \
      TRNS, TRNS, TRNS, TRNS,             SPC,              TRNS, TRNS, NO,   MPRV, MPLY, MNXT, \
      TRNS, TRNS                                                                                \
    ),
    KEYMAP(   // LAYER 3
      FN15, F1,   F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,  F12,  VOLD, VOLU, \
      TRNS, NO,   UP,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,   NO,         \
      TRNS, LEFT, DOWN, RIGHT,NO,   NO,   NO,   INS,  HOME, PGUP, BSPC, NO,         NO,         \
      TRNS, NO,   NO,   NO,   NO,   NO,   NO,   DEL,  END,  PGDN, NO,         TRNS, MSTP, NO,   \
      TRNS, TRNS, TRNS, TRNS,             SPC,              TRNS, TRNS, NO,   MPRV, MPLY, MNXT, \
      TRNS, TRNS                                                                                \
    ),
};

// id for user defined functions
enum function_id {
    ESC,
    PROGRAMMING,
    VIM_SAVE,
    VIM_QUIT,
};

// Fn action definition
const action_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),          // FN1 switch to Emacs layer
    [2] = ACTION_LAYER_MOMENTARY(2),          // FN2 switch to layer 2
    [3] = ACTION_LAYER_MOMENTARY(3),          // FN3 switch to layer 3
    [4] = ACTION_LAYER_MOMENTARY(1),          // FN1 footswitch to Emacs layer
    [13] = ACTION_FUNCTION(ESC),              // Special ESC key.
    [15] = ACTION_FUNCTION(PROGRAMMING),      // Program the Teensy.
    [20] = ACTION_MACRO(VIM_SAVE),            // Save a file in VIM
    [21] = ACTION_MACRO(VIM_QUIT),            // Quit VIM
    [30] = ACTION_MODS_TAP_KEY(MOD_LCTL, KC_ENT) // Left CTRL and Enter
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;

    switch (id) {
        case ESC:
            special_esc(event.pressed);
            break;

        case PROGRAMMING:
            clear_keyboard();
            dprint("Jump to bootloader... ");
            _delay_ms(100);
            bootloader_jump(); // not return
            dprint("not supported.\n");
            break;
    }
}

const macro_t* action_get_macro(keyrecord_t* record, uint8_t id, uint8_t opt) {
    keyevent_t event = record->event;

    switch (id) {
        case VIM_SAVE:
            // Waiting is necessary due to NeoVIM
            return (event.pressed ?
                    MACRO(T(ESC), W(10), D(LSFT), T(SCLN), U(LSFT), T(W), T(ENT), END) :
                    MACRO_NONE);

        case VIM_QUIT:
            // Waiting is necessary due to NeoVIM
            return (event.pressed ?
                    MACRO(T(ESC), W(10), D(LSFT), T(SCLN), U(LSFT), T(Q), T(ENT), END) :
                    MACRO_NONE);
    }

    return MACRO_NONE;
}

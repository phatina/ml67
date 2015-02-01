#include "keymap_common.h"

/* KEYMAP
    K00,K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E,\
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,    \
    K20,   K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C,       \
    K30,     K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D,\
    K40, K41, K42, K43,           K44,          K45, K46, K47, K48, K49, K4A \

      ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS,      \
      ESC,  A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   DEL, \
      LCTL, LGUI, LALT, FN1,              SPC,              FN1,  RALT, RGUI, LEFT, DOWN, RGHT \

      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS,             TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
*/

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: plain */
    KEYMAP(   // LAYER 0: Default
      ESC,  1,    2,    3,    4,    5,    6,    7,    8,    9,    0,    MINS, EQL,  BSPC, GRV, \
      TAB,  Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,    LBRC, RBRC, BSLS,      \
      CAPS, A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN, QUOT,       ENT,       \
      LSFT, Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,       RSFT, UP,   DEL, \
      LCTL, LGUI, LALT, FN1,              SPC,              FN1,  RALT, RGUI, LEFT, DOWN, RGHT \
    ),
    KEYMAP(   // LAYER 1: Function1
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS,      \
      TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,       TRNS, TRNS, TRNS,\
      TRNS, TRNS, TRNS, TRNS,             TRNS,             TRNS, TRNS, TRNS, TRNS, TRNS, TRNS \
    ),
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),          // FN1 switch to layer 1
};

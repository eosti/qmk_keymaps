#pragma once

#include QMK_KEYBOARD_H

#ifdef OS_DETECTION_ENABLE
#include "eosti_osdetect.h"
#endif

// Macros
// TODO: make these work on Windows too
#define WM_R        LCTL(KC_RGHT)       // Moves the MacOS WM to the right
#define WM_L        LCTL(KC_LEFT)       // ...and to the left
#define WM_MC       LCTL(KC_UP)         // Enters MacOS Mission Control

#define WEB_R       LCTL(KC_PGDN)       // Change tabs to the right on Firefox, Chrome
#define WEB_L       LCTL(KC_PGUP)       // ...and to the left

#define TMUX_LEADER "a"

enum custom_keycodes {
    TMUX_U = SAFE_RANGE,
    TMUX_D,
    TMUX_L,
    TMUX_R,
    TMUX_WN,    // Window next
    TMUX_WL,    // Window last
};


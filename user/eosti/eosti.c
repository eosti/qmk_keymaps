#include "eosti.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TMUX_WN:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(TMUX_LEADER) "n");
      }
      break;

    case TMUX_WL:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(TMUX_LEADER) "l");
      }
      break;

    case TMUX_L:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(TMUX_LEADER) SS_TAP(X_LEFT));
      }
      break;

    case TMUX_R:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(TMUX_LEADER) SS_TAP(X_RIGHT));
      }
      break;

    case TMUX_D:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(TMUX_LEADER) SS_TAP(X_DOWN));
      }
      break;

    case TMUX_U:
      if (record->event.pressed) {
          SEND_STRING(SS_LCTL(TMUX_LEADER) SS_TAP(X_UP));
      }
      break;

  }
  return true;
};

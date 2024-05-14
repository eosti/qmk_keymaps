#include "eosti_osdetect.h"

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
            layer_off(_WINDOWS);
            break;
        case OS_IOS:
            break;
        case OS_WINDOWS:
            layer_on(_WINDOWS);
            break;
        case OS_LINUX:
            break;
        case OS_UNSURE:
            break;
    }
    return true;
}

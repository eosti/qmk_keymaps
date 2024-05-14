SRC += eosti.c

ifeq ($(strip $(OS_DETECTION_ENABLE)), yes)
  SRC += eosti_osdetect.c
endif

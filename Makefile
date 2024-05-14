USER = eosti

# TODO: make it so you can not put the leading / on versions
KEYBOARDS = irisv3 planck bdn9 maypad nyquist
PATH_irisv3 = keebio/iris
VERSION_irisv3 = /rev4
PATH_planck = planck
VERSION_planck = /rev6_drop
PATH_bdn9 = keebio/bdn9
VERSION_bdn9 = /rev1
PATH_maypad = keyhive/maypad
PATH_nyquist = keebio/nyquist
VERSION_nyquist = /rev4

all: $(KEYBOARDS)

.PHONY: $(KEYBOARDS)
$(KEYBOARDS):
	# init submodule
	git submodule update --init --recursive

	# cleanup old symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

	# add new symlinks
	ln -s $(shell pwd)/user/$(USER) qmk_firmware/users/$(USER)
	ln -s $(shell pwd)/$@ qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER)

	# run lint check (non-strict)
	# cd qmk_firmware; qmk lint -km $(USER) -kb $(PATH_$@)$(VERSION_$@)

	# run build
	make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $(PATH_$@)$(VERSION_$@):$(USER)

	# cleanup symlinks
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf obj_*
	rm -f *.elf
	rm -f *.map
	rm -f *.hex
	rm -f *.tmp
	for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	rm -rf qmk_firmware/users/$(USER)
	cd qmk_firmware; qmk clean

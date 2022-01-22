build:
	qmk compile -km Ad01
	ls qmk_firmware/.build

flash:
	qmk flash -km Ad01

.PHONY: setup
setup:
	./setup

.PHONY: edit
edit:
	nvim ./qmk_firmware/keyboards/crkbd/keymaps/Ad01/keymap.c

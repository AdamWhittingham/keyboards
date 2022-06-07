.PHONY: install edit flash build default
	
default: flash

build:
	qmk compile -km Ad01
	ls qmk_firmware/.build

flash:
	qmk flash -km Ad01

install:
	./install

edit:
	$$EDITOR ./qmk_firmware/keyboards/crkbd/keymaps/Ad01/keymap.c

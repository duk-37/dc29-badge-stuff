CC := clang
OBJCOPY := llvm-objcopy
SRC_DIR := ./src
INC_DIR := ./inc
FLAGS := -O2 -nostdlib -mthumb --target=armv6-none-eabi -I $(INC_DIR)
OUTPUT_DIR := ./output
OUTPUT_FILE := music
BIN_OUT_FILE := music.bin
WELD_OUT_FILE := music.weld
UF2_OUT_FILE := music.uf2


convert: weld
	python3 scripts/uf2conv.py $(OUTPUT_DIR)/$(WELD_OUT_FILE) -o $(OUTPUT_DIR)/$(UF2_OUT_FILE)

weld: build
	python3 scripts/weld.py resources/flash.bin $(OUTPUT_DIR)/$(BIN_OUT_FILE) $(OUTPUT_DIR)/$(WELD_OUT_FILE)

build: setup
	$(CC) $(FLAGS) $(SRC_DIR)/* -o $(OUTPUT_DIR)/$(OUTPUT_FILE)
	$(OBJCOPY) --dump-section .text=$(OUTPUT_DIR)/$(BIN_OUT_FILE) $(OUTPUT_DIR)/$(OUTPUT_FILE)

setup:
	mkdir -p output

clean:
	rm -rf output
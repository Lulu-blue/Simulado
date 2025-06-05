CC       := gcc
CFLAGS   := -Wall -Wextra -Werror -O3
LDFLAGS  := -lm
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   := heap_sort_app
INCLUDE  := -Iinclude/
SRC      := $(wildcard src/*.c)  # Agora busca arquivos .c

OBJECTS  := $(SRC:src/%.c=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET) run

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) $(LDFLAGS) -o $@ $(OBJECTS)

.PHONY: all build clean debug release run

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CFLAGS += -DDEBUG -g
debug: all

release: CFLAGS += -O3
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

run:
	@./$(APP_DIR)/$(TARGET)
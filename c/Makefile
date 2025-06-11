CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3 -Iinclude
SRC_DIR = src
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/objects
BIN_DIR = $(BUILD_DIR)

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
TARGET = $(BIN_DIR)/heap_sort_benchmark

DATA_DIR = data
DATA_FILE = $(DATA_DIR)/ratings.csv

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

prepare-data:
	@mkdir -p $(DATA_DIR)
	@if [ ! -f $(DATA_FILE) ]; then \
		echo "Arquivo ratings.csv não encontrado em $(DATA_DIR)/"; \
		echo "Por favor, coloque o arquivo ratings.csv em um destes locais:"; \
		echo "1. $(DATA_DIR)/ratings.csv"; \
		echo "2. ./ratings.csv"; \
		echo "3. ../data/ratings.csv"; \
		exit 1; \
	fi

run: $(TARGET) prepare-data
	@echo "Executando benchmark..."
	@./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean run prepare-data
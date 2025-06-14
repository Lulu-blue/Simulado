
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude/ -g
LDFLAGS = 

SRC_DIR = src
OBJ_DIR = build/obj
EXEC_DIR = bin
INC_DIR = include

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
EXEC = $(EXEC_DIR)/programa

DEPS = $(wildcard $(INC_DIR)/*.h)

$(shell mkdir -p $(OBJ_DIR) $(EXEC_DIR))

.PHONY: all clean run

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(EXEC_DIR)

run: $(EXEC)
	./$(EXEC)
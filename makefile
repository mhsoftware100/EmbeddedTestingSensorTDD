CC = gcc
CFLAGS = -Wall -Werror -I$(SRC_DIR) -I$(UNITY_SRC_DIR) -I$(TEST_DIR)
LDFLAGS =

SRC_DIR = src
UNITY_SRC_DIR = Unity/src
TEST_DIR = test
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
RESULT_DIR = $(BUILD_DIR)/results

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
UNITY_SRC_FILES = $(wildcard $(UNITY_SRC_DIR)/*.c)
TEST_FILES = $(wildcard $(TEST_DIR)/*.c)

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) \
            $(patsubst $(UNITY_SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(UNITY_SRC_FILES)) \
            $(patsubst $(TEST_DIR)/%.c, $(OBJ_DIR)/%.o, $(TEST_FILES))

TARGET = $(BUILD_DIR)/firmware

RESULTS = $(patsubst $(TEST_DIR)/Test%.c, $(RESULT_DIR)/Test%.txt, $(TEST_FILES))

all: create_dirs $(TARGET)

$(TARGET): $(OBJ_FILES)
	@$(CC) $(LDFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(UNITY_SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

create_dirs:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(RESULT_DIR)

clean:
	@rm -rf $(BUILD_DIR)/*

.PHONY: all clean create_dirs test

# The extracted Unity part for displaying results
$(RESULT_DIR)/Test%.txt: $(TARGET)
	@./$< > $@ 2>&1

test: CFLAGS += -DTEST
test: create_dirs $(RESULTS)
	@echo "-----------------------\nIGNORES:\n-----------------------"
	@grep -s IGNORE $^ || true
	@echo "-----------------------\nFAILURES:\n-----------------------"
	@grep -s FAIL $^ || true
	@echo "-----------------------\nPASSED:\n-----------------------"
	@grep -s PASS $^ || true
	@echo "\nDONE"


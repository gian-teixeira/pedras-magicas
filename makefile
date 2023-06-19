PROJ_NAME=tp3

SRC_DIR=src
BUILD_DIR=build
INCLUDE_DIR=include
BIN_DIR=bin
C_SOURCE=$(wildcard $(SRC_DIR)/*.c)
H_SOURCE=$(wildcard $(INCLUDE_DIR)/*.h)
OBJ=$(subst .c,.o,$(subst $(SRC_DIR),$(BUILD_DIR),$(C_SOURCE)))

CC=gcc
CC_FLAGS=-c -I include/ -pthread -w 
 
all: $(PROJ_NAME)
	
$(PROJ_NAME): $(OBJ)
	$(CC) $^ -o $@
	@printf '\nBuild is done: tp3\n'

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p build
	$(CC) -c $< $(CC_FLAGS) -o $@

clean:
	rm -rf build/

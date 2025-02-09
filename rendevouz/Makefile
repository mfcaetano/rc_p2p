# Name of the final executable
TARGET = rendezvous

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I$(INCLUDE_DIR)

# List of source files
SRCS = $(SRC_DIR)/rendezvous.c $(SRC_DIR)/help_menu.c

# Generate object files by replacing .c with .o
OBJS = $(SRCS:.c=.o)

# Default build rule
all: $(TARGET)

# Compile the final program
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(BIN_DIR)/$(TARGET)

# Rule to compile .c files into .o
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDE_DIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled files
clean:
	rm -f $(SRC_DIR)/*.o $(BIN_DIR)/$(TARGET)

# Full cleanup (includes temporary files)
distclean: clean
	rm -f *~

run: $(TARGET)
	./$(BIN_DIR)/$(TARGET)

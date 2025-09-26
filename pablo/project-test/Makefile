# Compiler settings
CC = gcc
CXX = g++
CFLAGS = -Wall -Wextra -pedantic -g -O0
CXXFLAGS = -Wall -Wextra -pedantic -g -O0 -std=c++17

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INCLUDE_DIR = include

# Files
C_SRCS = $(wildcard $(SRC_DIR)/*.c)
CPP_SRCS = $(wildcard $(SRC_DIR)/*.cpp)
C_OBJS = $(C_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CPP_OBJS = $(CPP_SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJS = $(C_OBJS) $(CPP_OBJS)

# Target executable name (Con extensión .exe para Windows)
TARGET_NAME = program
TARGET = $(BIN_DIR)/$(TARGET_NAME).exe

# Default target
all: directories $(TARGET)

# Creación de Directorios: usa 'IF NOT EXIST' de Windows.
directories:
	@echo Creando directorios: $(OBJ_DIR) y $(BIN_DIR)
	mkdir $(OBJ_DIR)
	mkdir $(BIN_DIR)

# Link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

# Compile C source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Compile C++ source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpieza de Archivos: usa DEL y RMDIR de Windows.
clean:
	@echo Limpiando archivos de compilacion...
	-DEL /S /Q $(OBJ_DIR)\*.* 2> nul
	-RMDIR /S /Q $(OBJ_DIR) 2> nul
	-DEL /S /Q $(BIN_DIR)\*.* 2> nul
	-RMDIR /S /Q $(BIN_DIR) 2> nul

# Clean and rebuild
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild directories run
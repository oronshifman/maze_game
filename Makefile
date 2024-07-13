OBJS = test/main.cpp src/MazeGame.cpp src/Buffer.cpp src/Sprite.cpp

CC = g++

COMPILER_FLAGS = -Wall -Wextra

INCLUDE_DIR = include

DEBUG_FLAG = -g

OBJ_NAME = build/MazeGame

all: $(OBJS)
	$(CC) $(COMPILER_FLAGS) $(DEBUG_FLAG) -o $(OBJ_NAME) $(OBJS) -I $(INCLUDE_DIR)
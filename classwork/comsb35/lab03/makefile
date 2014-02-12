# simple makefile for lab02
CC = g++
FILES = Circle.cpp Circle.h Point.cpp Point.h testCircle.cpp
OUT_EXE = out_executable
C_FLAGS = -Wall

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(C_FLAGS)

clean:
		rm -f *.o core $(OUT_EXE)

rebuild: clean build

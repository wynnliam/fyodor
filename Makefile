COMPILER= g++

EXEC_NAME= fyodo.out
OBJ= ./bin/obj/*.o

# Commands and their prerequisites
ALL_PREREQ= main.o vector2d.o aabb.o

all: clean compile_all link_all

# All source files, their corresponding .o files,
# and the command to compile that source file
MAIN_S= ./src/main.cpp
MAIN_O= ./bin/obj/main.o
main.o: $(MAIN_S)
	$(COMPILER) -c $(MAIN_S) -o $(MAIN_O)

VECTOR2D_S= ./src/vector2d.cpp
VECTOR2D_O=./bin/obj/vector2d.o
vector2d.o: $(VECTOR2D_S)
	$(COMPILER) -c $(VECTOR2D_S) -o $(VECTOR2D_O)

AABB_S= ./src/aabb.cpp
AABB_O= ./bin/obj/aabb.o
aabb.o: $(AABB_S)
	$(COMPILER) -c $(AABB_S) -o $(AABB_O)

# Specific build recipies
.phony: clean
clean:
	-rm ./bin/*.out $(OBJ)

compile_all: $(ALL_PREREQ)

link_all:
	$(COMPILER) $(OBJ) -o ./bin/$(EXEC_NAME)


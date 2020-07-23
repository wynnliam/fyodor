COMPILER= g++
FLAGS=-g --std=c++20

EXEC_NAME= fyodo.out
OBJ= ./bin/obj/*.o

# Commands and their prerequisites
ALL_PREREQ= main.o vector2d.o aabb.o ray.o

all: clean compile_all link_all

# All source files, their corresponding .o files,
# and the command to compile that source file
MAIN_S= ./src/main.cpp
MAIN_O= ./bin/obj/main.o
main.o: $(MAIN_S)
	$(COMPILER) $(FLAGS) -c $(MAIN_S) -o $(MAIN_O)

VECTOR2D_S= ./src/vector2d.cpp
VECTOR2D_O =./bin/obj/vector2d.o
vector2d.o: $(VECTOR2D_S)
	$(COMPILER) $(FLAGS) -c $(VECTOR2D_S) -o $(VECTOR2D_O)

RAY_S= ./src/ray.cpp
RAY_O= ./bin/obj/ray.o
ray.o: $(RAY_S)
	$(COMPILER) $(FLAGS) -c $(RAY_S) -o $(RAY_O)

AABB_S= ./src/aabb.cpp
AABB_O= ./bin/obj/aabb.o
aabb.o: $(AABB_S)
	$(COMPILER) $(FLAGS) -c $(AABB_S) -o $(AABB_O)

# Specific build recipies
.phony: clean
clean:
	-rm ./bin/*.out $(OBJ)

compile_all: $(ALL_PREREQ)

link_all:
	$(COMPILER) $(OBJ) -o ./bin/$(EXEC_NAME)


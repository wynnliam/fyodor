COMPILER= g++

EXEC_NAME= fyodo.out
OBJ= ./bin/obj/*.o

# Commands and their prerequisites
ALL_PREREQ= main.o

all: clean compile_all link_all

# All source files, their corresponding .o files,
# and the command to compile that source file
MAIN_S= ./src/main.cpp
MAIN_O= ./bin/obj/main.o
main.o: $(MAIN_S)
	$(COMPILER) -c $(MAIN_S) -o $(MAIN_O)


.phony: clean
clean:
	-rm ./bin/*.out $(OBJ)

compile_all: $(ALL_PREREQ)

link_all:
	$(COMPILER) $(OBJ) -o ./bin/$(EXEC_NAME)


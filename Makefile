COMPILER= g++
FLAGS=-g --std=c++20
LINKER_FLAGS= -lm -lGL -lGLU -lglut -lglfw -lIL

EXEC_NAME= fyodor.out
OBJ= ./bin/obj/*.o

# Commands and their prerequisites
ALL_PREREQ= main.o vector2d.o aabb.o ray.o render.o shader_program.o tilemap.o \
			texture.o tile_atlas.o state.o state_simulation.o

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

RENDER_S= ./src/render.cpp
RENDER_O= ./bin/obj/render.o
render.o: $(RENDER_S)
	$(COMPILER) $(FLAGS) -c $(RENDER_S) -o $(RENDER_O)

TILEMAP_S=./src/tilemap.cpp
TILEMAP_O= ./bin/obj/tilemap.o
tilemap.o: $(TILEMAP_S)
	$(COMPILER) $(FLAGS) -c $(TILEMAP_S) -o $(TILEMAP_O)

SHADER_PROGRAM_S= ./src/shader_program.cpp
SHADER_PROGRAM_O= ./bin/obj/shader_program.o
shader_program.o: $(SHADER_PROGRAM_S)
	$(COMPILER) $(FLAGS) -c $(SHADER_PROGRAM_S) -o $(SHADER_PROGRAM_O)

TEXTURE_S= ./src/texture.cpp
TEXTURE_O= ./bin/obj/texture.o
texture.o: $(TEXTURE_S)
	$(COMPILER) $(FLAGS) -c $(TEXTURE_S) -o $(TEXTURE_O)

TILE_ATLAS_S= ./src/tile_atlas.cpp
TILE_ATLAS_O= ./bin/obj/tile_atlas.o
tile_atlas.o: $(TILE_ATLAS_S)
	$(COMPILER) $(FLAGS) -c $(TILE_ATLAS_S) -o $(TILE_ATLAS_O)

STATE_S= ./src/state.cpp
STATE_O= ./bin/obj/state.o
state.o: $(STATE_S)
	$(COMPILER) $(FLAGS) -c $(STATE_S) -o $(STATE_O)

STATE_SIM_S= ./src/state_simulation.cpp
STATE_SIM_O= ./bin/obj/state_simulation.o
state_simulation.o: $(STATE_SIM_S)
	$(COMPILER) $(FLAGS) -c $(STATE_SIM_S) -o $(STATE_SIM_O)

# Specific build recipies
.phony: clean
clean:
	-rm ./bin/*.out $(OBJ)

compile_all: $(ALL_PREREQ)

link_all:
	$(COMPILER) $(OBJ) $(LINKER_FLAGS) -o ./bin/$(EXEC_NAME)


// Liam Wynn, 7/31/2020, Fyodor

/*
	A tile map is responsible for two things:
	1. rendering
	2. walls - which we won't do for awhile because there
	is no reason for handling collisions right now.

	To do this, I want to define a vertex buffer object
	that this will encapsulate.
*/

#ifndef TILEMAP
#define TILEMAP

#include "./tile_atlas.h"
#include <memory>

namespace fyodor {
	class tilemap {
		public:
			/*
				Preconditions:
					- Must have a properly loaded texture
				Postconditions:
					- Sets the properties needed for the tilemap.
				Side effects:
					- N/A
				Notes:
					- N/A
			*/
			tilemap(unsigned int w, unsigned int h, std::shared_ptr<tile_atlas> a);
			~tilemap();

			/*
				Preconditions:
					- Tilemap properly initialized
				Postconditions:
					- Sets the tile at [row, col] to type. See Notes
					- Modifies map_vao_data to reflect change.
				Side Effects:
					- None
				Notes:
					- row and col must be within the bounds of tile map.
					- Type must be a valid texture id for atlas.
				Returns:
					- None
			*/
			void set_tile(const unsigned int row, const unsigned int col, const unsigned int type);

            void bind();
            void unbind();

			void render();

		private:
			// Describes the dimensions of the map
			unsigned int width, height;
			// Reference to the tile atlas used in this map.
			std::shared_ptr<tile_atlas> atlas;

			// I really hate to use a "dumb" pointer, but OpenGL
			// insists on these.
			float* map_vao_data;

			// OpenGL identifiers for VAO/VBO data
			unsigned int vao_id, vbo_id;
	};
}

#endif


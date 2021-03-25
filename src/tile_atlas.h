// Liam Wynn, 8/18/2020, Fyodor

/*
	The tile atlas is a class that defines how one can look-up tile
	texture for a map. Basically, you give the tile atlas a texture,
	which is an N x M grid of tile textures. Now, suppose I want
	to assign a particular tile in my map the texture 5. Then
	we give 5 to the tile atlas, and it will figure out what
	texture that corresponds to.
*/

#ifndef TILE_ATLAS
#define TILE_ATLAS

#include <memory>
#include <vector>
#include <glm/glm.hpp>
#include "./texture.h"

namespace fyodor {
	class tile_atlas {
		public:
			/*
				Preconditions:
					- Successfully loaded a texture into memory.
				Postconditions:
					- map_tex, num_rows, num_cols assigned values.
				Side effects:
					- None
				Returns:
					- None
				Notes:
					- None
			*/
			tile_atlas(std::shared_ptr<texture> tex);

			/*
				Preconditions:
					- None
				Postconditions:
					- None
				Side-effects:
					- None
				Returns:
					- The uv coordinates for texture at a given index.
				Notes:
					- texture_index must be between 0 and num_rows * num_cols.
					If not, we use the value 0.
			*/
			std::vector<glm::vec2> uv_coords(const unsigned int texture_index);

            /*
              Preconditions:
                - map_tex loaded properly
              Postconditions:
                - Binds map_tex for rendering
              Side-effects:
                - Modifies OpenGL state machine.
              Returns:
                - None
              Notes:
                - When done, call unbind_tex.
            */
            void bind_tex();

            /*
              Preconditions:
                - map_tex binded
              Postconditions:
                - Unbinds map_tex for rendering
              Side-effects:
                - Modifies OpenGL state machine.
              Returns:
                - None
              Notes:
            */
            void unbind_tex();

		private:
			std::shared_ptr<texture> map_tex;
			unsigned int num_rows, num_cols;
	};
}

#endif

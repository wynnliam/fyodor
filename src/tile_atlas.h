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

		private:
			std::shared_ptr<texture> map_tex;
			unsigned int num_rows, num_cols;
	};
}

#endif

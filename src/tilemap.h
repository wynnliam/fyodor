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

#include "./texture.h"
#include <memory>

namespace fyodor {
	class tilemap {
		public:
			/*
				Preconditions:
					- Must have a properly loaded texture
				Postconditions:
					- Sets the properties needed for the tilemap.
					You can now construct the tilemap as you please,
					and then call construct_vao.
				Side effects:
					- N/A
				Notes:
					- N/A
			*/
			tilemap(unsigned int w, unsigned int h, std::shared_ptr<texture> tex);

		private:
			// Describes the dimensions of the map
			unsigned int width, height;
			// Reference to the texture used by this map
			std::shared_ptr<texture> map_tex;
	};
}

#endif


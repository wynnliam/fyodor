// Liam Wynn, 7/31/2020, Fyodor

/*
	A tile map is responsible for two things:
	1. rendering
	2. walls - which we won't do for awhile because there
	is no reason for handling collisions right now.
*/

#ifndef TILEMAP
#define TILEMAP

namespace fyodor {
	class tilemap {
		public:
			
		private:
			// Describes the dimensions of the map
			unsigned int width, height;
	};
}

#endif


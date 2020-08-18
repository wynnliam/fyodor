// Liam Wynn, 8/18/2020, Fyodor

#include "./tile_atlas.h"

using namespace std;
using namespace fyodor;

// TODO: Move to constants class
// Size of a tile in pixels.
const unsigned int TILE_SIZE = 16;

tile_atlas::tile_atlas(shared_ptr<texture> tex) : map_tex(tex) {
	num_rows = map_tex->get_height() / 16;
	num_cols = map_tex->get_width() / 16;
}



// Liam Wynn, 7/31/2020, Fyodor

#include "./tilemap.h"

using namespace fyodor;
using namespace std;

tilemap::tilemap(unsigned int w, unsigned int h, shared_ptr<texture> tex) : width(w), height(h), map_tex(tex) {
	unsigned int tile_count = width * height;

	// Two floats for a position, and two floats
	// for a tex coordinate. Thus, 4 floats per vert.
	// 3 verts per triangle. So 12 floats per triangle.
	// 2 triangles per tile. So 24 floats per tile.
	unsigned int num_floats = 24 * tile_count;
	map_vao_data = new float[num_floats];

	// TODO: Finish me!
}

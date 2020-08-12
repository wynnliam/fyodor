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

	unsigned int index, vao_index;
	for(unsigned int x = 0; x < width; x++) {
		for(unsigned int y = 0; y < height; y++) {
			index = y * width + x;
			vao_index = 24 * index;

			// First triangle top left vert
			map_vao_data[index] = x - 0.5f;
			map_vao_data[index + 1] = y + 0.5f;

			// First triangle top left vert uv
			// TODO: Tile atlas!
			map_vao_data[index + 2] = 0.0f;
			map_vao_data[index + 3] = 1.0f;

			// First triangle top right vert
			map_vao_data[index + 4] = x + 0.5f;
			map_vao_data[index + 5] = y + 0.5f;

			// First triangle top right vert uv
			map_vao_data[index + 6] = 1.0f / 3.0f;
			map_vao_data[index + 7] = 1.0f;

			// First triangle bottom left vert
			map_vao_data[index + 8] = x - 0.5f;
			map_vao_data[index + 9] = y - 0.5f;

			// First triangle bottom left vert uv
			map_vao_data[index + 10] = 0.0f;
			map_vao_data[index + 11] = 0.5f;

			// Second triangle  bottom left vert
			map_vao_data[index + 12] = x - 0.5f;
			map_vao_data[index + 13] = y - 0.5f;

			// Second triangle bottom left vert uv
			map_vao_data[index + 14] = 0.0f;
			map_vao_data[index + 15] = 0.5f;

			// Second triangle bottom right
			map_vao_data[index + 16] = x + 0.5f;
			map_vao_data[index + 17] = y - 0.5f;

			// Second triangle bottom right uv
			map_vao_data[index + 18] = 1.0f / 3.0f;
			map_vao_data[index + 19] = 0.5f;

			// Second triangle top right vert
			map_vao_data[index + 20] = x + 0.5f;
			map_vao_data[index + 21] = y + 0.5f;

			// First triangle top right vert uv
			map_vao_data[index + 22] = 1.0f / 3.0f;
			map_vao_data[index + 23] = 1.0f;
		}
	}
}

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

vector<glm::vec2> tile_atlas::uv_coords(const unsigned int texture_index) {
	vector<glm::vec2> result;
	unsigned int row, col;

	row = texture_index / num_cols;
	col = texture_index % num_cols;

	// Top left
	result.push_back(glm::vec2((float)col / num_cols, (float)row / num_rows));
	// Top right
	result.push_back(glm::vec2((float)(col + 1) / num_cols, (float)row / num_rows));
	// Bottom left
	result.push_back(glm::vec2((float)col / num_cols, (float)(row + 1) / num_rows));
	// Bottom right
	result.push_back(glm::vec2((float)(col + 1) / num_cols, (float)(row + 1) / num_rows));

	return result;
}


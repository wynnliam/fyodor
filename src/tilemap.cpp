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
			map_vao_data[vao_index] = x - 0.5f;
			map_vao_data[vao_index + 1] = y + 0.5f;

			// First triangle top left vert uv
			// TODO: Tile atlas!
			map_vao_data[vao_index + 2] = 0.0f;
			map_vao_data[vao_index + 3] = 0.0f;

			// First triangle top right vert
			map_vao_data[vao_index + 4] = x + 0.5f;
			map_vao_data[vao_index + 5] = y + 0.5f;

			// First triangle top right vert uv
			map_vao_data[vao_index + 6] = 1.0f / 3.0f;
			map_vao_data[vao_index + 7] = 0.0f;

			// First triangle bottom left vert
			map_vao_data[vao_index + 8] = x - 0.5f;
			map_vao_data[vao_index + 9] = y - 0.5f;

			// First triangle bottom left vert uv
			map_vao_data[vao_index + 10] = 0.0f;
			map_vao_data[vao_index + 11] = 0.5f;

			// Second triangle  bottom left vert
			map_vao_data[vao_index + 12] = x - 0.5f;
			map_vao_data[vao_index + 13] = y - 0.5f;

			// Second triangle bottom left vert uv
			map_vao_data[vao_index + 14] = 0.0f;
			map_vao_data[vao_index + 15] = 0.5f;

			// Second triangle bottom right
			map_vao_data[vao_index + 16] = x + 0.5f;
			map_vao_data[vao_index + 17] = y - 0.5f;

			// Second triangle bottom right uv
			map_vao_data[vao_index + 18] = 1.0f / 3.0f;
			map_vao_data[vao_index + 19] = 0.5f;

			// Second triangle top right vert
			map_vao_data[vao_index + 20] = x + 0.5f;
			map_vao_data[vao_index + 21] = y + 0.5f;

			// First triangle top right vert uv
			map_vao_data[vao_index + 22] = 1.0f / 3.0f;
			map_vao_data[vao_index + 23] = 0.0f;
		}
	}

	glGenVertexArrays(1, &vao_id);
	glGenBuffers(1, &vbo_id);
	glBindVertexArray(vao_id);
	glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * num_floats, map_vao_data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

tilemap::~tilemap() {
	if(map_vao_data)
		delete[] map_vao_data;

	map_vao_data = NULL;

	glDeleteBuffers(1, &vbo_id);
	glDeleteVertexArrays(1, &vao_id);
}

void tilemap::render() {
	// Clears color
	glClear(GL_COLOR_BUFFER_BIT);

	glBindVertexArray(vao_id);
	glDrawArrays(GL_TRIANGLES, 0, 6 * width * height);

	// Swap window buffers at end of rendering.
	glutSwapBuffers();
}

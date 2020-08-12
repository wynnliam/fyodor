// Liam Wynn, 8/1/2020, Fyodor

#include "./texture.h"
#include <iostream>

using namespace fyodor;
using namespace std;

texture::texture(const std::string& path) {
	// Temporary IL texture id
	ILuint image_id;

	// First, we need to generate our image id
	ilGenImages(1, &image_id);
	// Now we need to bind the image in DevIL so
	// we can do operations on it.
	ilBindImage(image_id);

	if(!ilLoadImage(path.c_str())) {
		cout << "Failed to load image: " << path << endl;
		id = 0;
		return;
	}

	ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);

	GLuint* raw_data = (GLuint*)ilGetData();
	GLuint img_w = (GLuint)ilGetInteger(IL_IMAGE_WIDTH);
	GLuint img_h = (GLuint)ilGetInteger(IL_IMAGE_HEIGHT);

	// Save the image dimensions
	width = img_w;
	height = img_h;

	// Okay now we generate a texture in OpenGL.
	glGenTextures(1, &id);
	// Now bind it so we can do OpenGL operations on it.
	glBindTexture(GL_TEXTURE_2D, id);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img_w, img_h, 0, GL_RGBA, GL_UNSIGNED_BYTE, raw_data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	ilDeleteImage(image_id);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void texture::bind() {
	glBindTexture(GL_TEXTURE_2D, id);
}

void texture::render() {
	// Clears color
	glClear(GL_COLOR_BUFFER_BIT);

	// Will attempt to draw a rectangle

	// Reset all transformations.
	glLoadIdentity();

	if(id == 0)
		return;

	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, id);

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f); glVertex2f(-1, -1);
		glTexCoord2f(1.0f, 1.0f); glVertex2f(1, -1);
		glTexCoord2f(0.0f, 1.0f); glVertex2f(1, 1);
		glTexCoord2f(0.0f, 0.0f); glVertex2f(-1, 1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, 0);

	glPopMatrix();
	glutSwapBuffers();
}

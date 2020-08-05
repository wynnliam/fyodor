// Liam Wynn, 8/1/2020, Fyodor

#include "./texture.h"
#include <iostream>

using namespace fyodor;
using namespace std;

texture::texture(const std::string& path) {
	// Temporary IL texture id
	ILuint image_id;
	// We copy this into OpenGL so then we can get rid of
	// the IL data
	ILubyte* raw_image_data;

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

	// Okay the texture data is loaded. Now we need to copy it into raw_image_data.
	raw_image_data = new ILubyte[ilGetInteger(IL_IMAGE_SIZE_OF_DATA)];
	// Now we copy the data from IL into raw_image_data.
	ilCopyPixels(0, 0, 0, ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
				 ilGetInteger(IL_IMAGE_DEPTH), ilGetInteger(IL_IMAGE_FORMAT),
				 ilGetInteger(IL_IMAGE_TYPE), raw_image_data);

	// Okay now we generate a texture in OpenGL.
	glGenTextures(1, &id);
	// Now bind it so we can do OpenGL operations on it.
	glBindTexture(GL_TEXTURE_2D, id);
	// Now we copy the raw image data into OpenGL.
	glTexImage2D(GL_TEXTURE_2D, 0, ilGetInteger(IL_IMAGE_FORMAT),
				 ilGetInteger(IL_IMAGE_WIDTH), ilGetInteger(IL_IMAGE_HEIGHT),
				 0, ilGetInteger(IL_IMAGE_FORMAT), GL_UNSIGNED_BYTE,
				 (GLubyte*)raw_image_data);

	// Now we clean up!
	ilDeleteImage(image_id);
	glBindTexture(GL_TEXTURE_2D, 0);
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

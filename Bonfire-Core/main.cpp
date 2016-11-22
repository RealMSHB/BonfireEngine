#include "src/graphics/window.h"


int main()
{
	using namespace bonfire;
	using namespace graphics;

	Window window("Bonfire", 800, 600);

	glClearColor(0.2f, 0.5f, 0.2f, 1.0f);

	while (!window.closed())
	{
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.25f, -0.25f);
		glVertex2f( 0.0f, 1.0f);
		glVertex2f( 1.0f, -1.0f);
		glEnd();
		window.update();
	}

	return 0;
}
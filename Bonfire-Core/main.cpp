#include "src/graphics/window.h"


int main()
{
	using namespace bonfire;
	using namespace graphics;

	Window window("Bonfire", 1024, 720 );

	glClearColor(0.2f, 0.5f, 0.2f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		std::cout << "X : " << x << " Y : " << y << "\n";


		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f( 0.0f, 0.5f);
		glVertex2f( 0.5f, -0.5f);
		glEnd();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}

	return 0;
}
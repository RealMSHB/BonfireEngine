#include "src/graphics/window.h"
#include "src/maths/maths.h"


int main()
{
	using namespace bonfire;
	using namespace graphics;
	using namespace maths;

	Window window("Bonfire", 1024, 720 );

	glClearColor(0.2f, 0.5f, 0.2f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec3 a(2.0f, 2.0f,4.0f);
	vec3 b(1.0f, 2.0f,5.0f);
	vec3 c = a + b;

	while (!window.closed())
	{
		window.clear();

		std::cout << a << "\n";


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
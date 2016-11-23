#include "window.h"

namespace bonfire { namespace graphics {

	void windowResize(GLFWwindow *window, int width, int height);

	Window::Window(const char *title, int width, int height) 
	{
		m_Title = title;
		m_Width = width;
		m_Height = height;
		if(!init())
		{
			glfwTerminate();
		}
	}

	Window::~Window()
	{	
		glfwTerminate();
	}


	bool Window::init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to Inlitialize GLFW !!" << "\n";
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
		if(!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to Creat GLFW window !!" << "\n";
			return false;
		}
		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResize);

		if(glewInit() != GLEW_OK)
		{
			std::cout << "Could not initialaize GLEW !!!" << "\n";
			return false;
		}

		std::cout << "OpenGL : " << glGetString(GL_VERSION) << "\n";

		return true;
	}


	void Window::clear() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update()
	{
		glfwPollEvents();
		//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
		glfwSwapBuffers(m_Window);
	}

	bool Window::closed() const
	{
		return glfwWindowShouldClose(m_Window) == 1;
	}

	void windowResize(GLFWwindow *window , int width , int height)
	{
		glViewport(0, 0, width, height);
	}
} } 
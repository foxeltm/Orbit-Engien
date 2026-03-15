
#include "obpch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
//my application 

#include <GLFW/glfw3.h>

namespace Orbit
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.4f, 0.6f, 0.1f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}
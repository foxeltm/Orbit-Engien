#include "obpch.h"

#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"
//my application 

namespace Orbit
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			OB_TRACE(e.ToString());
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			OB_TRACE(e.ToString());
		}

		while (true);
	}
}
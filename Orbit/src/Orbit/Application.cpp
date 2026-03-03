#include "Application.h"
#include "AplicationEvent.h"
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
			OB_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			OB_TRACE(e);
		}

		while (true);
	}
}
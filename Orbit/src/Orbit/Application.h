#pragma once

#include "Core.h"

namespace Orbit
{

	class ORBIT_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();
}


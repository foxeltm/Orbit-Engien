#include "Orbit.h"

class Sandbox : public Orbit::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

namespace Orbit
{
	Orbit::Application* Orbit::CreateApplication()
	{
		return new Sandbox();
	}
}
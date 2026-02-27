#pragma once

#ifdef OB_PLATFORM_WINDOWS

extern Orbit::Application* Orbit::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Orbit::CreateApplication();
	app->Run();
	delete app;
}
#endif

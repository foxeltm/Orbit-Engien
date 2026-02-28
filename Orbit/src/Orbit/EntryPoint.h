#pragma once


#ifdef OB_PLATFORM_WINDOWS

extern Orbit::Application* Orbit::CreateApplication();

int main(int argc, char** argv)
{
	Orbit::Log::Init();
	OB_CORE_WARN("Initialized Core Logger");
	int a = 5;
	OB_INFO("Hello! Var={0}", a);

	auto app = Orbit::CreateApplication();
	app->Run();
	delete app;
}
#endif

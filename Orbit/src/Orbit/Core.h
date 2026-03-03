#pragma once

#ifdef OB_PLATFORM_WINDOWS
	#ifdef OB_BUILD_DLL
		#define ORBIT_API __declspec(dllexport)
	#else
		#define ORBIT_API __declspec(dllimport)
	#endif
#else
	#error Orbit only supports Windows!
#endif

#define BIT(x) (1 << x)
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

#ifdef  OB_ENABLE_ASSERTS
	#define OB_ASSERT(x, ...) { if(!(x)) { OB_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define OB_CORE_ASSERT(x, ...) { if(!(x)) { OB_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define OB_ASSERT(x, ...)
	#define OB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
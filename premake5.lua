workspace "Orbit"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

 outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

 IncludeDir = {}
IncludeDir["GLFW"] = "Orbit/vendor/GLFW/include"

include "Orbit/vendor/GLFW"

project "Orbit"
	location "Orbit"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	pchheader "obpch.h"
	pchsource "Orbit/src/obpch.cpp"


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	
	}

	includedirs
	{	
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OB_PLATFORM_WINDOWS",
			"OB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OB_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/utf-8"	

	filter { "system:windows", "configurations:Debug" }
		buildoptions "/utf-8"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	
	}

	includedirs
	{
		"Orbit/vendor/spdlog/include",
		"Orbit/src"
	}

	links
	{
		"Orbit"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

	defines
	{
		"OB_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "OB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OB_DIST"
		optimize "On"

	filter { "system:windows", "configurations:Release" }
		buildoptions "/utf-8"	

	filter { "system:windows", "configurations:Debug" }
		buildoptions "/utf-8"
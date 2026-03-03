#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Orbit
{

	class ORBIT_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define OB_CORE_ERROR(...)     ::Orbit::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OB_CORE_WARN(...)      ::Orbit::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OB_CORE_INFO(...)      ::Orbit::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OB_CORE_TRACE(...)     ::Orbit::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OB_CORE_FATAL(...)     ::Orbit::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define OB_ERROR(...)     ::Orbit::Log::GetClientLogger()->error(__VA_ARGS__)
#define OB_WARN(...)      ::Orbit::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OB_INFO(...)      ::Orbit::Log::GetClientLogger()->info(__VA_ARGS__)
#define OB_TRACE(...)     ::Orbit::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OB_FATAL(...)     ::Orbit::Log::GetClientLogger()->fatal(__VA_ARGS__)
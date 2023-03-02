#pragma once

#include <memory>
#include "Core.h"
#include "../../vendor/spdlog/include/spdlog/spdlog.h"
#include "../../vendor/spdlog/include/spdlog/fmt/ostr.h"
#include "../../vendor/spdlog/include/spdlog/sinks/stdout_color_sinks.h"

namespace Maroni {

	class MARONI_API Log
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
#define MR_CORE_TRACE(...)   ::Maroni::Log::getCoreLogger()->trace(__VA_ARGS__)
#define MR_CORE_INFO(...)    ::Maroni::Log::getCoreLogger()->info(__VA_ARGS__)
#define MR_CORE_WARN(...)    ::Maroni::Log::getCoreLogger()->warn(__VA_ARGS__)
#define MR_CORE_ERROR(...)   ::Maroni::Log::getCoreLogger()->error(__VA_ARGS__)
#define MR_CORE_FATAL(...)   ::Maroni::Log::getCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MR_TRACE(...)        ::Maroni::Log::getClientLogger()->trace(__VA_ARGS__)
#define MR_INFO(...)         ::Maroni::Log::getClientLogger()->info(__VA_ARGS__)
#define MR_WARN(...)         ::Maroni::Log::getClientLogger()->warn(__VA_ARGS__)
#define MR_ERROR(...)        ::Maroni::Log::getClientLogger()->error(__VA_ARGS__)
#define MR_FATAL(...)        ::Maroni::Log::getClientLogger()->fatal(__VA_ARGS__)
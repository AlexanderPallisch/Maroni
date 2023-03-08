#pragma once


#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

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
#define MR_CORE_TRACE(...)   ::Maroni::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MR_CORE_INFO(...)    ::Maroni::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MR_CORE_WARN(...)    ::Maroni::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MR_CORE_ERROR(...)   ::Maroni::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MR_CORE_FATAL(...)   ::Maroni::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define MR_TRACE(...)        ::Maroni::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MR_INFO(...)         ::Maroni::Log::GetClientLogger()->info(__VA_ARGS__)
#define MR_WARN(...)         ::Maroni::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MR_ERROR(...)        ::Maroni::Log::GetClientLogger()->error(__VA_ARGS__)
#define MR_FATAL(...)        ::Maroni::Log::GetClientLogger()->fatal(__VA_ARGS__)
#pragma once

#ifdef MR_PLATFORM_WINDOWS
	#ifdef MR_BUILD_DLL
		#define MARONI_API __declspec(dllexport)
	#else
		#define MARONI_API __declspec(dllimport)
	#endif
#else
	#error Maroni only supports Windows!
#endif

#ifdef MR_DEBUG
#define MR_ENABLE_ASSERTS
#endif

#ifdef MR_ENABLE_ASSERTS
#define MR_ASSERT(x, ...) { if (!(x)) { CN_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define MR_CORE_ASSERT(x, ...) { if (!(x)) { CN_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define MR_ASSERT(x, ...)
#define MR_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

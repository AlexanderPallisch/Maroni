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

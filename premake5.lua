workspace "Maroni"
	architecture "x64"
    startproject "Sandbox"
	configurations
	{
		"Debug",
		"Release",
		"Dist"		
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Maroni"
	location "Maroni"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

	}

	includedirs
	{
		"%{prj.name}src"
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MR_PLATFORM_WINDOWS",
			"MR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "MR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MR_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",

	}

	includedirs
	{
		"Maroni/vendor/spdlog/include"
	}

	links
	{
		"Maroni"
	}

	filter "system:windows"
		cppdialect "C++17"		
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"MR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "MR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "MR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "MR_DIST"
		optimize "On"

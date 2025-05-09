workspace "Nova"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Nova/vendor/GLFW/include"
IncludeDir["Glad"] = "Nova/vendor/Glad/include"
IncludeDir["ImGui"] = "Nova/vendor/imgui"
IncludeDir["glm"] = "Nova/vendor/glm"

group "Dependencies"
	include "Nova/vendor/GLFW"
	include "Nova/vendor/Glad"
	include "Nova/vendor/imgui"
	include "Nova/vendor/glm"
group ""

project "Nova"
	location "Nova"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nvpch.h"
	pchsource "Nova/src/nvpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"glm",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"NV_PLATFORM_WINDOWS",
			"NV_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "NV_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NV_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Nova/vendor/spdlog/include",
		"Nova/src",
		"Nova/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Nova"
	}

	filter "system:windows"
		systemversion "latest"
		buildoptions "/utf-8"

		defines
		{
			"NV_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NV_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "NV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "NV_DIST"
		runtime "Release"
		optimize "on"
workspace "AllDataStructures"
	architecture "x86_64"
	startproject "AllDataStructures"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	flags
	{
		"MultiProcessorCompile"
	}

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "AllDataStructures"
	location"AllDataStructures"
	kind"ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" .. outputdir ..  "/%{prj.name}")
	objdir("bin-int/" .. outputdir ..  "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.tpp",
		"%{prj.name}/src/**.cpp"
	}


	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "DS_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "DS_REALESE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "DS_DIST"
		runtime "Release"
		optimize "on"


workspace "RisingDragon"
	architecture "x64"
	
	configurations  
	{ 
		"Debug", 
		"Release", 
		"Dist"  --Dist Referes to "Distribution", thus been the version of the game that will be downloadable to CLIENTS
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "RisingDragon"
	location "RisingDragon"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RD_PLATAFORM_WINDOWS",
			"RD_BUILD_DLL"
		}

		postbuildcommands
		{
			("copy %{cfg.buildtarget.relpath} ../bin/" .. outputdir .."/SandBox")
		}


	filter "configurations:Debug"
		defines "RD_DEBUG"
		symbols "On"

		filter "configurations:Release"
		defines "RD_RELEASE"
		optimize "On"

		filter "configurations:Dist"
		defines "RD_DIST"
		optimize "On"


project "SandBox"
	location "SandBox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs{ "RisingDragon/src" }

	links 
	{
		"RisingDragon"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RD_PLATAFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "RD_DEBUG"
		symbols "On"

		filter "configurations:Release"
		defines "RD_RELEASE"
		optimize "On"

		filter "configurations:Dist"
		defines "RD_DIST"
		optimize "On"


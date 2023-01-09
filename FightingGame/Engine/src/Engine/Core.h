#pragma once

#ifdef EG_PLATAFORM_WINDOWS
	#ifdef EG_BUILD_DLL
		#define  EG_API __declspec(dllexport)
	#else
		#define EG_API __declspec(dllimport)
	#endif	
#else
	#error Only Windows Supported!
#endif
#pragma once

#ifdef RD_PLATAFORM_WINDOWS
	#ifdef RD_BUILD_DLL
		#define  RD_API __declspec(dllexport)
	#else
		#define RD_API __declspec(dllimport)
	#endif	
#else
	#error Only Windows Supported!
#endif

#include <stdio.h>

// Bit Field, "define bit X by one shifted by X places"
// It's usefull to create a mask where each bit represent one Event Category
#define BIT(x) (1 << x)


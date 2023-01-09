#pragma once

#include "Core.h"

namespace RisingDragon
{

	 class RD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run(void);
	};

	 // To be Defined in CLIENT
	 Application* CreateApplication();
}

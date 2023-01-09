#pragma once

#include "Core.h"

namespace Engine
{
	 class EG_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run(void);
	};

}

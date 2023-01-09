#pragma once

#ifdef RD_PLATAFORM_WINDOWS

extern RisingDragon::Application* RisingDragon::CreateApplication();

int main(int argc, char** argv)
{
	RisingDragon::Application* App = RisingDragon::CreateApplication();
	App->Run();
	delete App;
}
#else
	#error Only Windows Supported!
#endif
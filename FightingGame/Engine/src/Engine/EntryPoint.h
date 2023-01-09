#pragma once

#ifdef EG_PLATAFORM_WINDOWS

extern Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	auto App = Engine::CreateApplication();
	App->Run();
	delete App;
}
#else
	#error Only Windows Supported!
#endif
#include <Engine.h>

class SandBox : public Engine::Application
{
	SandBox()
	{
	}

	~SandBox()
	{
	
	}
};

void main()
{
	SandBox* sandbox = new SandBox();
	sandbox->Run();
	delete sandbox;

}
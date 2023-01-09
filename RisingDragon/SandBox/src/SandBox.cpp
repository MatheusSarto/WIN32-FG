#include <RisingDragon.h>

class SandBox : public RisingDragon::Application
{
public:
	SandBox() {}
	~SandBox() {}
};

RisingDragon::Application* RisingDragon::CreateApplication()
{
	return new SandBox();

}
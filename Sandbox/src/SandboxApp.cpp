#include <Maroni.h>

class Sandbox : public Maroni::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};


Maroni::Application* Maroni::CreateApplication()
{
	return new Sandbox();
}

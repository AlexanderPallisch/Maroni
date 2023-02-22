#pragma once

#include <stdio.h>

#ifdef MR_PLATFORM_WINDOWS

extern Maroni::Application* Maroni::CreateApplication();

int main(int argc, char** argv)
{
	printf("Maroni Engine running..\n");
	auto app = Maroni::CreateApplication();
	app->Run();
	delete app;
}

#endif
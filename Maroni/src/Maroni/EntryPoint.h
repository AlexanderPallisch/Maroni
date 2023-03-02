#pragma once

#include <stdio.h>

#ifdef MR_PLATFORM_WINDOWS

extern Maroni::Application* Maroni::CreateApplication();

int main(int argc, char** argv)
{
	printf("Maroni Engine running..\n");
	Marono::Log::Init();
	MR_CORE_WARN("Init Log");
	MR_INFO("Init APP");
	auto app = Maroni::CreateApplication();
	app->Run();
	delete app;
}

#endif
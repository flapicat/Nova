#include <iostream>

#include "Nova/core/App.h"

#ifdef NV_PLATFORM_WINDOWS

extern Nova::App* Nova::Create();

int main(int argc, char** argv)
{
	Nova::Log::init();
	auto app = Nova::Create();
	app->Run();
	delete app;
}

#endif
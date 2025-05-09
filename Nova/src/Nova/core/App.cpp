#include "nvpch.h"
#include "App.h"

namespace Nova
{
	App* App::s_Instance = nullptr;

	App::App()
	{
		s_Instance = this;
	}

	void App::Run()
	{
		while (m_running)
		{
			std::cout << "Running\n";
		}
	}

	void App::OnClose()
	{
	}

	void App::OnEvent()
	{
	}

	void App::OnUpdate()
	{
	}

	App::~App() { OnClose(); }
}
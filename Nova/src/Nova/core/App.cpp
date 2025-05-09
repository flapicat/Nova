#include "nvpch.h"
#include "App.h"

namespace Nova
{
#define BIND_EVENT_FN(x) std::bind(&App::x, this, std::placeholders::_1)

	App* App::s_Instance = nullptr;

	App::App()
	{
		s_Instance = this;
	}

	void App::Run()
	{

		while (m_running)
		{
		}
	}

	void App::OnClose()
	{
	}

	void App::OnEvent(Event& e)
	{
		EventHandler handler(e);
		handler.Handle<WindowCloseEvent>(BIND_EVENT_FN(OnWindowCloseEvent));

	}

	void App::OnUpdate()
	{
	}

	bool App::OnWindowCloseEvent(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}

	App::~App() { OnClose(); }
}
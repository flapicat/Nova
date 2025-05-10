#include "nvpch.h"
#include "App.h"

#include <glad/glad.h>

namespace Nova
{
#define BIND_EVENT_FN(x) std::bind(&App::x, this, std::placeholders::_1)

	App* App::s_Instance = nullptr;

	App::App()
	{
		s_Instance = this;

		m_window = std::unique_ptr<Window>(Window::Create());
		m_window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	void App::Run()
	{
		while (m_running)
		{
			glClearColor(0.1,0.1,0.1,0.1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_layerstack)
				layer->OnUpdate();

			m_window->OnUpdate();
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

	void App::PushLayer(Layer* layer)
	{
		m_layerstack.pushLayer(layer);
		layer->OnAttach();
	}

	void App::PushOverlay(Layer* overlay)
	{
		m_layerstack.pushOverlay(overlay);
		overlay->OnAttach();
	}

	bool App::OnWindowCloseEvent(WindowCloseEvent& event)
	{
		m_running = false;
		return true;
	}

	App::~App() { OnClose(); }
}
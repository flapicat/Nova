#pragma once
#include "Nova/event/AppEvent.h"

#include "Nova/core/Window.h"
#include "Nova/core/LayerStack.h"

namespace Nova
{
	class App
	{
	public:
		App();
		~App();
		void Run();
		void OnClose();
		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static App* Get() { return s_Instance; }
	private:
		bool OnWindowCloseEvent(WindowCloseEvent& event);
	private:
		std::unique_ptr<Window> m_window;
		LayerStack m_layerstack;
		static App* s_Instance;
		bool m_running = true;
	};

	App* Create();
}
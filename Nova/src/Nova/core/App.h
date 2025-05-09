#pragma once
#include "Nova/event/AppEvent.h"

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
		void OnUpdate();
		inline static App* Get() { return s_Instance; }
	private:
		bool OnWindowCloseEvent(WindowCloseEvent& event);
	private:
		static App* s_Instance;
		bool m_running = true;
	};

	App* Create();
}
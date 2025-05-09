#pragma once

namespace Nova
{
	class App
	{
	public:
		App();
		~App();
		void Run();
		void OnClose();
		void OnEvent();
		void OnUpdate();
		inline static App* Get() { return s_Instance; }
	private:
		static App* s_Instance;
		bool m_running = true;
	};

	App* Create();
}
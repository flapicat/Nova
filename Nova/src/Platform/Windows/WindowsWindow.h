#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Nova/core/Window.h"

namespace Nova
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int getWidth() const override { return m_data.Width; };
		inline unsigned int getHeight() const override { return m_data.Height; };

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_data.EventCallback = callback; };
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return m_window; };
	private:
		virtual void init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_window;

		struct WindowData
		{
			std::string Title;
			int Width;
			int Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};
		WindowData m_data;
	};

}


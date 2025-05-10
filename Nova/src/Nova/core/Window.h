#pragma once
#include "nvpch.h"
#include "Nova/event/Event.h"

#include <string>

namespace Nova
{
	struct WindowProps
	{
		int Width;
		int Height;
		std::string Title;

		WindowProps(const std::string& title = "Nova Engine",
			int width = 1600,
			int height = 900)
			:Title(title), Width(width), Height(height)
		{
		}
	};

	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};

}
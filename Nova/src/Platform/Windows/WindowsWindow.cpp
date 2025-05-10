#include "nvpch.h"
#include "WindowsWindow.h"

#include "Nova/event/AppEvent.h"
#include "Nova/event/KeyboardEvent.h"
#include "Nova/event/MouseEvent.h"

namespace Nova
{
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		glfwSwapInterval(enabled);
		m_data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_data.VSync;
	}

	void WindowsWindow::init(const WindowProps& props)
	{
		m_data.Width = props.Width;
		m_data.Height = props.Height;
		m_data.Title = props.Title;

		int success = glfwInit();
		if (!success)
		{
			NV_ERROR("FAILD to init GLFW");
		}

		NV_CORE_INFO("Creating window: {0} ({1}, {2})", m_data.Title, m_data.Width, m_data.Width);

		m_window = glfwCreateWindow(m_data.Width, m_data.Height, m_data.Title.c_str(), nullptr, nullptr);
		
		NV_CORE_INFO("SUCCES Window Created : {0} ({1}, {2})", m_data.Title, m_data.Width, m_data.Width);

		glfwMakeContextCurrent(m_window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		if(!status) NV_CORE_ERROR("Failed to initialize Glad!");

		NV_CORE_INFO("OpenGL info:");
		NV_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		NV_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		NV_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		glfwSetWindowUserPointer(m_window, &m_data);
		SetVSync(true);

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(m_window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.EventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetCharCallback(m_window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				KeyTypedEvent event(keycode);
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action)
				{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallback(event);
					break;
				}
				}
			});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_window);
	}
}
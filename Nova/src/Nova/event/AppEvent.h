#pragma once
#include "Event.h"

namespace Nova
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default; 

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowCloseEvent";
			return ss.str();
		}

		EVENT_TYPE(WindowClose);
		EVENT_CATEGORY(EventCategoryApplication);
	};

	class WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			:m_Width(width), m_Height(height) 
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_Width << " " << m_Height;
			return ss.str();
		}

		EVENT_TYPE(WindowClose);
		EVENT_CATEGORY(EventCategoryApplication);
	private:
		unsigned int m_Width, m_Height;
	};
}
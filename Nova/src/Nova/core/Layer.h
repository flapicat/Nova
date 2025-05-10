#pragma once
#include <string>

#include "Nova/event/Event.h"

namespace Nova
{
	class Layer
	{
	public:
		Layer(const std::string name)
			:m_DebugName(name)
		{
		}

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() const { return m_DebugName; }
	private:
		std::string m_DebugName;
	};
}
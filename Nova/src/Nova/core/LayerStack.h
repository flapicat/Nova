#pragma once
#include <vector>
#include "Layer.h"

namespace Nova
{
	class LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* overlay);
		void popLayer(Layer* layer);
		void popOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return m_layerStack.begin(); }
		std::vector<Layer*>::iterator end() { return m_layerStack.end(); }
	private:
		std::vector<Layer*> m_layerStack;
		unsigned int m_layerIndex = 0
			;
	};
}
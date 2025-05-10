#include "nvpch.h"
#include "LayerStack.h"

namespace Nova
{

	LayerStack::LayerStack()
	{
	}
	
	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_layerStack)
			delete layer;
	}
	
	void LayerStack::pushLayer(Layer* layer)
	{
		m_layerStack.emplace(m_layerStack.begin() + m_layerIndex, layer);
		m_layerIndex++;
	}
	
	void LayerStack::pushOverlay(Layer* overlay)
	{
		m_layerStack.emplace_back(overlay);
	}
	
	void LayerStack::popLayer(Layer* layer)
	{
		auto it = std::find(m_layerStack.begin(), m_layerStack.end(), layer);
		if (it != m_layerStack.end())
		{
			m_layerStack.erase(it);
			m_layerIndex--;
		}
	}
	
	void LayerStack::popOverlay(Layer* overlay)
	{
		auto it = std::find(m_layerStack.begin(), m_layerStack.end(), overlay);
		if (it != m_layerStack.end())
		{
			m_layerStack.erase(it);
		}
	}

}
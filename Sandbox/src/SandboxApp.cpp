#include "Nova.h"

class ExampleLayer : public Nova::Layer
{
public:
	ExampleLayer()
		:Layer("ExampleLayer")
	{
	}

	virtual void OnAttach() override
	{
	}
	virtual void OnDetach() override
	{
	}
	virtual void OnUpdate() override
	{
		NV_TRACE("ON UPDATE EXAMPLE LAYER");
	}
	virtual void OnEvent(Nova::Event& event)
	{
	}
private:
};


class ExampleApp : public Nova::App
{
public:
	ExampleApp()
	{
		PushLayer(new ExampleLayer);
	}
private:
};

Nova::App* Nova::Create()
{
	return new ExampleApp;
}

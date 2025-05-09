#include "Nova.h"

class ExampleApp : public Nova::App
{
public:
	ExampleApp(){}
private:
};

Nova::App* Nova::Create()
{
	return new ExampleApp;
}

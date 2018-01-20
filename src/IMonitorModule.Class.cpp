#include "IMonitorModule.Class.hpp"

IMonitorModule::IMonitorModule(){}

IMonitorModule::IMonitorModule(IMonitorModule const &cc)
{
    *this = cc;
}

IMonitorModule::~IMonitorModule(){}

IMonitorModule &IMonitorModule::operator=(IMonitorModule const &input)
{
    (void) input;
	return (*this);
}

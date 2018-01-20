#include "IMonitorDisplay.Class.hpp"

IMonitorDisplay::IMonitorDisplay(){}

IMonitorDisplay::IMonitorDisplay(IMonitorDisplay const &cc)
{
    *this = cc;
}

IMonitorDisplay::~IMonitorDisplay(){}

IMonitorDisplay &IMonitorDisplay::operator=(IMonitorDisplay const &input)
{
    (void) input;
	return (*this);
}

#include "TermMonitor.Class.hpp"

TermMonitor::TermMonitor(){}

TermMonitor::TermMonitor(TermMonitor const &cc)
{
    *this = cc;
}

TermMonitor::~TermMonitor(){}

TermMonitor &TermMonitor::operator=(TermMonitor const &input)
{
    modules_to_display = input.modules_to_display;
	return (*this);
}


void TermMonitor::config(void)
{
    std::cout << "Please configure TermMonitor" << std::endl;
}

void TermMonitor::run(void)
{
    config();
    std::cout << nm.getInfo() << std::endl;
    std::cout << osim.getInfo() << std::endl;
    std::cout << dtm.getInfo() << std::endl;
    std::cout << "You are running the TermMonitor" << std::endl;
}

#include "GraphicMonitor.Class.hpp"

GraphicMonitor::GraphicMonitor(){}

GraphicMonitor::GraphicMonitor(GraphicMonitor const &cc)
{
    *this = cc;
}

GraphicMonitor::~GraphicMonitor(){}

GraphicMonitor &GraphicMonitor::operator=(GraphicMonitor const &input)
{
    modules_to_display = input.modules_to_display;
	return (*this);
}

void GraphicMonitor::config(void)
{
    std::cout << "Please configure GraphicModule." << std::endl;
}

void GraphicMonitor::run(void)
{
    config();
    std::cout << "You are running the GraphicMonitor" << std::endl;
}

#include "GraphicMonitor.Class.hpp"

GraphicMonitor::GraphicMonitor()
{
    window.create(sf::VideoMode(1200, 1000), "Graphic Monitor");
    font.loadFromFile("./fonts/cour.ttf");
}

GraphicMonitor::GraphicMonitor(GraphicMonitor const &cc)
{
    *this = cc;
}

GraphicMonitor::~GraphicMonitor(){}

GraphicMonitor &GraphicMonitor::operator=(GraphicMonitor const &input)
{
    modules_to_display = input.modules_to_display;
    font = input.font;
    window.create(sf::VideoMode(1200, 1000), "Graphic Monitor");
	return (*this);
}

void GraphicMonitor::display(void)
{
    sf::Text    full_str(cat.getInfo() +
						nm.getInfo() +
                        osim.getInfo() +
                        dtm.getInfo() +
                        cpum.getInfo() +
                        ramm.getInfo() +
                        ntm.getInfo(), font, 20);
    full_str.setFillColor(sf::Color::Green);
    window.draw(full_str);
    window.display();
}

void GraphicMonitor::refresh(void)
{
    window.clear(sf::Color::Black);
    display();
}

void GraphicMonitor::run(void)
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        refresh();
    }
    std::cout << "You are running the GraphicMonitor" << std::endl;
}

#include "GraphicMonitor.Class.hpp"

GraphicMonitor::GraphicMonitor()
{
    window.create(sf::VideoMode(800, 1000), "Graphic Monitor");
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
    window.create(sf::VideoMode(800, 1000), "Graphic Monitor");
	return (*this);
}

void GraphicMonitor::display(void)
{
    /*
sf::Text    nm_str(nm.getInfo(), font, 20);
    sf::Text    os_str(osim.getInfo(), font, 20);
    sf::Text    dtm_str(dtm.getInfo(), font, 20);
    sf::Text    cpum_str(cpum.getInfo(), font, 20);
    sf::Text    ramm_str(ramm.getInfo(), font, 20);
    sf::Text    ntm_str(ntm.getInfo(), font, 20);
    window.draw(nm_str);
    window.draw(os_str);
    window.draw(dtm_str);
    window.draw(cpum_str);
    window.draw(ramm_str);
    window.draw(ntm_str);*/

    sf::Text    full_str(nm.getInfo() +
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

void GraphicMonitor::config(void)
{
    std::cout << "Please configure GraphicModule." << std::endl;
}

void GraphicMonitor::run(void)
{
    config();
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

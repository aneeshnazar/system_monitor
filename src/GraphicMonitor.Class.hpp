#ifndef GRAPHICMONITOR_H
#define GRAPHICMONITOR_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "IMonitorDisplay.Class.hpp"
#include "DateTimeModule.Class.hpp"
#include "NameModule.Class.hpp"
#include "NetThruModule.Class.hpp"
#include "CPUModule.Class.hpp"
#include "RAMModule.Class.hpp"
#include "OSInfoModule.Class.hpp"

class GraphicMonitor : public IMonitorDisplay {
    private:
        unsigned int    modules_to_display;
        sf::Font        font;
        sf::RenderWindow  window;
        NameModule      nm;
        OSInfoModule    osim;
        DateTimeModule  dtm;
        CPUModule       cpum;
        RAMModule       ramm;
        NetThruModule   ntm;
	public:
        GraphicMonitor ();
        GraphicMonitor (GraphicMonitor const &cc);
        ~GraphicMonitor ();
        GraphicMonitor &operator=(GraphicMonitor const &input);
        void config();
        void display(void);
        void refresh(void);
        void run();
};
#endif

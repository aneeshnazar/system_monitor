#ifndef GRAPHICMONITOR_H
#define GRAPHICMONITOR_H

#include <iostream>
#include "IMonitorDisplay.Class.hpp"

class GraphicMonitor : public IMonitorDisplay {
    private:
        unsigned int    modules_to_display;
	public:
        GraphicMonitor ();
        GraphicMonitor (GraphicMonitor const &cc);
        ~GraphicMonitor ();
        GraphicMonitor &operator=(GraphicMonitor const &input);
        void config();
        void run();
};
#endif

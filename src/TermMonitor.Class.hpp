#ifndef TERMMONITOR_H
#define TERMMONITOR_H

#include <iostream>
#include "IMonitorDisplay.Class.hpp"

class TermMonitor : public IMonitorDisplay{
    private:
        unsigned int    modules_to_display;
	public:
        TermMonitor ();
        TermMonitor (TermMonitor const &cc);
        ~TermMonitor ();
        TermMonitor &operator=(TermMonitor const &input);
        void run();
        void config();
};
#endif

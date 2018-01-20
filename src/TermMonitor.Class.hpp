#ifndef TERMMONITOR_H
#define TERMMONITOR_H

#include <iostream>
#include "IMonitorDisplay.Class.hpp"
#include "DateTimeModule.Class.hpp"
#include "NameModule.Class.hpp"
#include "OSInfoModule.Class.hpp"

class TermMonitor : public IMonitorDisplay{
    private:
        unsigned int    modules_to_display;
        NameModule      nm;
        OSInfoModule    osim;
        DateTimeModule  dtm;
	public:
        TermMonitor ();
        TermMonitor (TermMonitor const &cc);
        ~TermMonitor ();
        TermMonitor &operator=(TermMonitor const &input);
        void run();
        void config();
};
#endif

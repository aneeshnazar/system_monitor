#ifndef TERMMONITOR_H
#define TERMMONITOR_H

#include <iostream>
#include <ncurses.h>
#include "IMonitorDisplay.Class.hpp"
#include "DateTimeModule.Class.hpp"
#include "NameModule.Class.hpp"
#include "NetThruModule.Class.hpp"
#include "CPUModule.Class.hpp"
#include "RAMModule.Class.hpp"
#include "OSInfoModule.Class.hpp"
#define FPS 60
#define CLOCKS_PER_FRAME (CLOCKS_PER_SEC / FPS)

class TermMonitor : public IMonitorDisplay{
    private:
        unsigned int    modules_to_display;
        NameModule      nm;
        OSInfoModule    osim;
        DateTimeModule  dtm;
        CPUModule       cpum;
        RAMModule       ramm;
        NetThruModule   ntm;
		int				_rows;
		int				_cols;
		int				_ch;
	public:
        TermMonitor ();
        TermMonitor (TermMonitor const &cc);
        ~TermMonitor ();
        TermMonitor &operator=(TermMonitor const &input);
        void run();
		void update();
		void print();
        void config();
		void resize();
		void drawBorder();
};
#endif

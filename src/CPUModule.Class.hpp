#ifndef CPUMODULE_H
#define CPUMODULE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <sys/sysctl.h>
#include <vector>
#include <cstdlib>
#include "IMonitorModule.Class.hpp"

class CPUModule : public IMonitorModule {
    private:
		size_t          size;
        bool            stuck;
		std::string     buf;
        int     process_total;
        int     process_running;
        int     process_stuck;
        int     process_sleeping;
        int     process_threads;
        double     load_avg1;
        double     load_avg2;
        double     load_avg3;
	public:
        CPUModule ();
        CPUModule (CPUModule const &cc);
        ~CPUModule ();
        CPUModule &operator=(CPUModule const &input);

		size_t getSize(void) const;
		void setSize(size_t _size);
		std::string getBuf(void) const;
		void setBuf(std::string _buf);
        std::string getInfo(void);
        void setInfo(void);
        void update(void);
        int getVisSize(void);
};

#endif

#ifndef IMONITORMODULE_H
#define IMONITORMODULE_H

#include <iostream>

class IMonitorModule {
    private:
	public:
        IMonitorModule ();
        IMonitorModule (IMonitorModule const &cc);
        ~IMonitorModule ();
        IMonitorModule &operator=(IMonitorModule const &input);
        virtual std::string getInfo(void) = 0;
        virtual int getVisSize(void) = 0;
        virtual void update(void) = 0;
};

#endif

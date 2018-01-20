#ifndef NETTHRUMODULE_H
#define NETTHRUMODULE_H

#include "IMonitorModule.Class.hpp"
#include <sstream>
#include <fstream>

class NetThruModule : public IMonitorModule {
    private:
	public:
        NetThruModule ();
        NetThruModule (NetThruModule const &cc);
        ~NetThruModule ();
        NetThruModule &operator=(NetThruModule const &input);
        std::string getInfo(void);
        void update(void);
        int getVisSize(void);
};
#endif

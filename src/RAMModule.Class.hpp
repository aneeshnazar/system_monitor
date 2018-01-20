#ifndef RAMMODULE_H
#define RAMMODULE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "IMonitorModule.Class.hpp"

class RAMModule : public IMonitorModule {
    private:
		double cpuUsageUser;
		double cpuUsageSys;
		double cpuUsageIdle;
		int ramUsed;
		int ramWired;
		int ramUnused;
	public:
        RAMModule ();
        RAMModule (RAMModule const &cc);
        ~RAMModule ();
        RAMModule &operator=(RAMModule const &input);

		double getCpuusageuser(void) const;
		void setCpuusageuser(double _cpuUsageUser);
		double getCpuusagesys(void) const;
		void setCpuusagesys(double _cpuUsageSys);
		double getCpuusageidle(void) const;
		void setCpuusageidle(double _cpuUsageIdle);
		int getRamused(void) const;
		void setRamused(int _ramUsed);
		int getRamwired(void) const;
		void setRamwired(int _ramWired);
		int getRamunused(void) const;
		void setRamunused(int _ramUnused);
        std::string getInfo(void);
        void update(void);
        int getVisSize(void);
};
#endif

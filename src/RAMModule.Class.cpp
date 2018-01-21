#include "RAMModule.Class.hpp"

RAMModule::RAMModule()
{
    setInfo();
}

RAMModule::RAMModule(RAMModule const &cc)
{
    *this = cc;
}

RAMModule::~RAMModule(){}

RAMModule &RAMModule::operator=(RAMModule const &input)
{
	cpuUsageUser = input.cpuUsageUser;
	cpuUsageSys = input.cpuUsageSys;
	cpuUsageIdle = input.cpuUsageIdle;
	ramUsed = input.ramUsed;
	ramWired = input.ramWired;
	ramUnused = input.ramUnused;
	return (*this);
}

double RAMModule::getCpuusageuser(void) const { return cpuUsageUser;}

void RAMModule::setCpuusageuser(double _cpuUsageUser){cpuUsageUser = _cpuUsageUser;}

double RAMModule::getCpuusagesys(void) const { return cpuUsageSys;}

void RAMModule::setCpuusagesys(double _cpuUsageSys){cpuUsageSys = _cpuUsageSys;}

double RAMModule::getCpuusageidle(void) const { return cpuUsageIdle;}

void RAMModule::setCpuusageidle(double _cpuUsageIdle){cpuUsageIdle = _cpuUsageIdle;}

int RAMModule::getRamused(void) const { return ramUsed;}

void RAMModule::setRamused(int _ramUsed){ramUsed = _ramUsed;}

int RAMModule::getRamwired(void) const { return ramWired;}

void RAMModule::setRamwired(int _ramWired){ramWired = _ramWired;}

int RAMModule::getRamunused(void) const { return ramUnused;}

void RAMModule::setRamunused(int _ramUnused){ramUnused = _ramUnused;}

void RAMModule::setInfo()
{
    std::system("top -l 1 | grep -E \"^CPU|^Phys\" > ./.raminfo");
    std::ifstream       ifs("./.raminfo");
    std::string         line = "";
    std::vector<std::string> info;
    while (1)
    {
        ifs >> line;
        if (line == "" || ifs.eof())
            break ;
        info.push_back(line);
    }
    ifs.close();
    cpuUsageUser = atof(info[2].c_str());
    cpuUsageSys = atof(info[4].c_str());
    cpuUsageIdle = atof(info[6].c_str());
    ramUsed = atoi(info[9].c_str());
    ramWired = atoi(info[11].substr(1).c_str());
    ramUnused = atoi(info[13].c_str());
}

std::string RAMModule::getInfo(void)
{
    std::stringstream    s;

    setInfo();
    s << "CPU Usage: " << std::endl;
    s << " User:\t\t\t" << cpuUsageUser << "%" << std::endl;
    s << " System:\t\t" << cpuUsageSys << "%" << std::endl;
    s << " Idle:\t\t\t" << cpuUsageIdle << "%" << std::endl << std::endl;

    s << " RAM:" << std::endl;
    s << " Used:\t\t\t" << ramUsed - ramWired << "MB" << std::endl;
    s << " Wired:\t\t\t" << ramWired << "MB" << std::endl;
    s << " Unused:\t\t" << ramUnused << "MB" << std::endl << std::endl;
    return (s.str());
}

void RAMModule::update(void)
{

}

int RAMModule::getVisSize(void)
{
    return (10);
}

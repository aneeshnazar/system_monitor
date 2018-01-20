#include "OSInfoModule.Class.hpp"
#include <sstream>

OSInfoModule::OSInfoModule(){}

OSInfoModule::OSInfoModule(OSInfoModule const &cc)
{
    *this = cc;
}

OSInfoModule::~OSInfoModule(){}

OSInfoModule &OSInfoModule::operator=(OSInfoModule const &input)
{
	name = input.name;
	return (*this);
}

struct utsname OSInfoModule::getName(void) const { return name;}

void OSInfoModule::setName(struct utsname _name){name = _name;}

std::string OSInfoModule::getInfo(void)
{
    std::stringstream s;

    s << "OS TYPE:\t\t" << name.sysname << std::endl << "OS RELEASE:\t\t" << name.release << std::endl;
    return (s.str());
}

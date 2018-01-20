#include "OSInfoModule.Class.hpp"

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

#include "NameModule.Class.hpp"

NameModule::NameModule(){}

NameModule::NameModule(NameModule const &cc)
{
    *this = cc;
}

NameModule::~NameModule(){}

NameModule &NameModule::operator=(NameModule const &input)
{
	hostname = input.hostname;
	username = input.username;
	return (*this);
}

std::string NameModule::getHostname(void) const { return hostname;}

void NameModule::setHostname(std::string _hostname){hostname = _hostname;}

std::string NameModule::getUsername(void) const { return username;}

void NameModule::setUsername(std::string _username){username = _username;}


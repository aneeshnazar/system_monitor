#include "NameModule.Class.hpp"
#include <sstream>
#include <unistd.h>

NameModule::NameModule()
{
    char    _hname[255];
    char    _uname[255];

    gethostname(_hname, 255);
    getlogin_r(_uname, 255);
    setHostname(_hname);
    setUsername(_uname);
}

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

std::string NameModule::getInfo(void)
{
    std::stringstream s;

    s << "Hostname:\t\t" << hostname << std::endl << " Username:\t\t" << username << std::endl;
    return (s.str());
}


void NameModule::update(void)
{

}

int NameModule::getVisSize(void)
{
    return (2);
}

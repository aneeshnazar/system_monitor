#include "NetThruModule.Class.hpp"

NetThruModule::NetThruModule(){}

NetThruModule::NetThruModule(NetThruModule const &cc)
{
    *this = cc;
}

NetThruModule::~NetThruModule(){}

NetThruModule &NetThruModule::operator=(NetThruModule const &input)
{
    (void) input;
	return (*this);
}

std::string NetThruModule::getInfo(void)
{
    std::stringstream    s;
    std::system("nettop -J bytes_in,bytes_out -x -l1 > ./.netinfo");
    std::ifstream       ifs("./.netinfo");
    std::string         out = "";
    std::string         line = "";


    s << "Network throughput: " << std::endl;
    while(getline(ifs, line))
    {
        s << line << std::endl;
    }
    return (s.str());
}

void NetThruModule::update(void)
{

}

int NetThruModule::getVisSize(void)
{
    return (0);
}

#include "NetThruModule.Class.hpp"

NetThruModule::NetThruModule(){ line_num = 1;}

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
        if (line.find("tcp") == std::string::npos && line.find("udp") == std::string::npos)
        {
            s << line.substr(line.find(' ')) << std::endl;
            ++line_num;
        }
    }
    return (s.str());
}

void NetThruModule::update(void)
{

}

int NetThruModule::getVisSize(void)
{
    return (line_num);
}

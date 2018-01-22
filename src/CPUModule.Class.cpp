#include "CPUModule.Class.hpp"

CPUModule::CPUModule()
{
    setInfo();
}

CPUModule::CPUModule(CPUModule const &cc)
{
    *this = cc;
}

CPUModule::~CPUModule(){}

CPUModule &CPUModule::operator=(CPUModule const &input)
{
	size = input.size;
	buf = input.buf;
	return (*this);
}

size_t CPUModule::getSize(void) const { return size;}

void CPUModule::setSize(size_t _size){size = _size;}

std::string CPUModule::getBuf(void) const { return buf;}

void CPUModule::setBuf(std::string _buf){buf = _buf;}

void CPUModule::setInfo(void)
{
    this->size = 128;
    char buff[size];
    sysctlbyname("machdep.cpu.brand_string", &buff, &size, NULL, 0);
    buf = std::string(buff);
    std::system("/usr/bin/top -n 1 | /usr/bin/head -n5 > .tmp");
    std::ifstream   ifs(".tmp");
    std::string     line = "";
    std::vector<std::string> info;
    while (1)
    {
        ifs >> line;
        if (line == "" || ifs.eof())
            break ;
        info.push_back(line);
    }
    ifs.close();

	if (info.size() >= 15)
	{
		process_total = atoi(info[1].c_str());
		process_running = atoi(info[3].c_str());
		process_stuck = atoi(info[5].c_str());
		process_sleeping = atoi(info[7].c_str());
		process_threads = atoi(info[9].c_str());
		stuck = (info[6] == "stuck");
		load_avg1 = atof(info[stuck ? 14 : 12].c_str());
		load_avg2 = atof(info[stuck ? 15 : 13].c_str());
		load_avg3 = atof(info[stuck ? 16 : 14].c_str());
	}
}

std::string CPUModule::getInfo(void)
{
    std::stringstream s;

    setInfo();
    s << "CPU Info:\t" << buf << std::endl;
    s << " Processes:\t" << std::endl;
    s << " Total:\t\t\t" << process_total << std::endl;
    s << " Running:\t\t" << process_running << std::endl;
    if (stuck)
        s << " Stuck:\t\t" << process_stuck << std::endl;
    s << " Sleeping:\t\t" << process_sleeping << std::endl;
    s << " Threads:\t\t" << process_threads << std::endl;
    return (s.str());
}

void CPUModule::update(void)
{

}

int CPUModule::getVisSize(void)
{
    return (6 + stuck);
}

#include "DateTimeModule.Class.hpp"

DateTimeModule::DateTimeModule()
{
    start_time = time(NULL);
}

DateTimeModule::DateTimeModule(DateTimeModule const &cc)
{
    *this = cc;
}

DateTimeModule::~DateTimeModule(){}

DateTimeModule &DateTimeModule::operator=(DateTimeModule const &input)
{
	start_time = input.start_time;
	return (*this);
}

time_t DateTimeModule::getStartTime(void) const { return start_time;}

void DateTimeModule::setStartTime(void){start_time = time(NULL);}

std::string DateTimeModule::getInfo(void)
{
    setStartTime();
    return asctime(localtime(&start_time));
}


void DateTimeModule::update(void)
{

}

int DateTimeModule::getVisSize(void)
{
    return (0);
}

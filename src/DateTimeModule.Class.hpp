#ifndef DATETIMEMODULE_H
#define DATETIMEMODULE_H

#include <ctime>
#include <iostream>
#include "IMonitorModule.Class.hpp"

class DateTimeModule : public IMonitorModule {
    private:
		time_t start_time;
	public:
        DateTimeModule ();
        DateTimeModule (DateTimeModule const &cc);
        ~DateTimeModule ();
        DateTimeModule &operator=(DateTimeModule const &input);

		time_t getStartTime(void) const;
		void setStartTime(void);
        std::string getInfo(void);
        void update(void);
        int getVisSize(void);
};
#endif

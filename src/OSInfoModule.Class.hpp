#ifndef OSINFOMODULE_H
#define OSINFOMODULE_H

#include <sys/utsname.h>
#include <iostream>
#include "IMonitorModule.Class.hpp"

class OSInfoModule : public IMonitorModule {
    private:
		struct utsname name;
	public:
        OSInfoModule ();
        OSInfoModule (OSInfoModule const &cc);
        ~OSInfoModule ();
        OSInfoModule &operator=(OSInfoModule const &input);

		struct utsname getName(void) const;
		void setName(struct utsname _name);
        std::string getInfo(void);
        void update(void);
        int getVisSize(void);
};
#endif

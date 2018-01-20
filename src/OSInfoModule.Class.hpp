#ifndef OSINFOMODULE_H
#define OSINFOMODULE_H

#include <sys/utsname.h>
#include <iostream>

class OSInfoModule {
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
};
#endif

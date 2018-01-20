#ifndef NAMEMODULE_H
#define NAMEMODULE_H

#include <iostream>

class NameModule {
    private:
		std::string hostname;
		std::string username;
	public:
        NameModule ();
        NameModule (NameModule const &cc);
        ~NameModule ();
        NameModule &operator=(NameModule const &input);

		std::string getHostname(void) const;
		void setHostname(std::string _hostname);
		std::string getUsername(void) const;
		void setUsername(std::string _username);
        std::string getInfo(void);
};
#endif

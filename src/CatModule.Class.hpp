#ifndef CATMODULE_H
#define CATMODULE_H

#include <iostream>
#include "IMonitorModule.Class.hpp"

class CatModule : public IMonitorModule {
    private:
		std::string cats[6];
		int whichCat;
	public:
        CatModule ();
        CatModule (CatModule const &cc);
        ~CatModule ();
        CatModule &operator=(CatModule const &input);

        std::string getInfo(void);
		void update();
        int getVisSize(void);
};
#endif

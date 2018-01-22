#include "CatModule.Class.hpp"

CatModule::CatModule() : whichCat(0)
{
	cats[0] = "   |\\_._/|  \n   | o o |  \n   (  T  )  \n  .^`-^-\'^. \n  `.  ;  .\' \n  | | | | | \n ((_((|))_))\n";
	cats[1] = "   |\\_._/|  \n   |  o o|  \n   (  T  )  \n  .^`-^-\'^. \n  `.  ;  .\' \n  | | | | | \n ((_((|))_))\n";
	cats[2] = "   |\\_._/|  \n   |o o  |  \n   (  T  )  \n  .^`-^-\'^. \n  `.  ;  .\' \n  | | | | | \n ((_((|))_))\n";
	cats[3] = "   |\\_._/|  \n   | 0 0 |  \n   (  T  )  \n  .^`-^-\'^. \n  `.  ;  .\' \n  | | | | | \n ((_((|))_))\n";
	cats[4] = "   |\\_._/|  \n   |-o^o-|  \n   (  T  )  \n  .^`-^-\'^. \n  `.  ;  .\' \n  | | | | | \n ((_((|))_))\n";
	cats[5] = "   |\\_._/|  \n   |-@~@-|  \n   (  T  )  \n  .^`-^-\'^. \n  `.  ;  .\' \n  | | | | | \n ((_((|))_))\n";
}

CatModule::CatModule(CatModule const &cc)
{
    *this = cc;
}

CatModule::~CatModule(){}

CatModule &CatModule::operator=(CatModule const &input)
{
	cats[0] = input.cats[0];
	cats[1] = input.cats[1];
	cats[2] = input.cats[2];
	cats[3] = input.cats[3];
	cats[4] = input.cats[4];
	cats[5] = input.cats[5];
	return (*this);
}


std::string CatModule::getInfo(void)
{
	std::string catMes = "Cat Module:\n";
	std::string fullCatMes = catMes + cats[whichCat];

	update();
    return (fullCatMes);
}

void CatModule::update(void)
{
	srand(clock());
	whichCat = rand() % 6;
}

int CatModule::getVisSize(void)
{
    return (8);
}

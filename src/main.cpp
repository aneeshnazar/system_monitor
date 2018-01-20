#include <iostream>
#include "TermMonitor.Class.hpp"
#include "GraphicMonitor.Class.hpp"

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        std::string arg(argv[1]);
        if (arg == "-g")
        {
            GraphicMonitor g;
            g.run();
        }
        else if (arg == "-t")
        {
            TermMonitor t;
            t.run();
        }
        else
        {
            std::cout << "Usage: ./ft_rush01 [flag]" << std::endl;
            std::cout << "flag options:" << std::endl;
            std::cout << "-t - runs ft_rush01 in terminal window" << std::endl;
            std::cout << "-g - runs ft_rush01 with graphical interface" << std::endl;
        }
    }
    else
    {std::cout << "Usage: ./ft_rush01 [flag]" << std::endl;
    std::cout << "flag options:" << std::endl;
    std::cout << "-t - runs ft_rush01 in terminal window" << std::endl;
    std::cout << "-g - runs ft_rush01 with graphical interface" << std::endl;}
    return 0;
}

/*
Add to makefile:

brew install qt

LDFLAGS:  -L/usr/local/opt/qt/lib
CPPFLAGS: -I/usr/local/opt/qt/include
*/

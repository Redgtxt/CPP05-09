#include "Rpn.hpp"
#include "Rpn.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    try
    {
        Rpn Rpn;
        if (argc != 2)
        {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        Rpn.calculate(argv[1]);
    }
    catch (const Rpn::RpnError& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

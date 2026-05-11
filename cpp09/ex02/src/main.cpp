#include "PmergeMe.hpp"


int main(int argc,char *argv[])
{
    try
    {
        if(argc > 2)
        {
            PmergeMe Pmerge;
            Pmerge.parseInput(argv);
    
            std::cout << std::endl;
    
            Pmerge.DoPmergeMe();
            return 1;
        }
        if(argc == 2)
        {
            PmergeMe Pmerge;
            Pmerge.parseInput(argv);
            std::cout << argv[1] << std::endl;
            return 1;
        }

        std::cerr << "Try Program name and a sequence of numbers" << std::endl;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
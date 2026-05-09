#include "PmergeMe.hpp"

int main(int argc,char *argv[])
{

    try
    {
        if(argc > 2)
        {
            PmergeMe Pmerge;
            Pmerge.populateVector(argv);
    
            //Printar vector para ver a info antes de a modificar
            std::cout << "-----------------------Inicio Programa -----------------" << std::endl;
            Pmerge.printVec(Pmerge.getNums());
    
            std::cout << std::endl;
    
            Pmerge.DoPmergeMe();
    
        }else{
            std::cerr << "Try Program name and a sequence of numbers" << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    return 0;
}
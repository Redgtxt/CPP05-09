#include "PmergeMe.hpp"

int main(int argc,char *argv[])
{
    (void) argv;
    if(argc > 2)
    {
        PmergeMe Pmerge;
        if(!Pmerge.populateVector(argv))
        {
            std::cout << "Algo deu errado la dentro peço desculpa meu chapa" << std::endl;
            return 1;
        }

        //Printar vector para ver a info antes de a modificar
        std::cout << "-----------------------Inicio Programa -----------------" << std::endl;
        Pmerge.printVec(Pmerge.getNums());

        std::cout << std::endl;

        Pmerge.DoPmergeMe();

    }else{
        std::cout << "Try Program name and a sequence of numbers" << std::endl;
    }

    return 0;
}
#include "Bureaucrat.hpp"
 
int main()
{
    //Grade is to high
    try {
        Bureaucrat z1("Joe", 200);
    } catch(const std::exception& e) {
        std::cout << "Erro no z1: " << e.what() << std::endl;
    }

    // Grade is to low
    try {
        Bureaucrat z2("Joe", -1);
    } catch(const std::exception& e) {
        std::cout << "Erro no z2: " << e.what() << std::endl;
    }

    //Decrement funcion
    try
    {   
        Bureaucrat dummy("Dummy",134);
        dummy.decrementGrade();
        std::cout << dummy;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

    
}
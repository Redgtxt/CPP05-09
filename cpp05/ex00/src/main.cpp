#include "Bureaucrat.hpp"
 
int main()
{
    //Grade is to low
    /*
    150 is the lowest grade so It will go to the catch
    */
    try {
        Bureaucrat z1("Joe", 200);
    } catch(const std::exception& e) {
        std::cout << "Erro no z1: " << e.what() << std::endl;
    }

    // Grade is to high

    /*
    1 is the highest grade so It will go to the catch
    */
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
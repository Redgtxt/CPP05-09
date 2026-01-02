#include "Bureaucrat.hpp"
 
int main()
{
    try
    {
        Bureaucrat z1("Joe",200);
        Bureaucrat z2("Joe",-1);
    }
    //Vai pegar a primeira exception que encontrar
    catch(const std::exception& e)
    {
    std::cout << "Exception: " << e.what() << std::endl;
    std::cout << "range 1-150" << std::endl;
    }
    /*
    catch(Bureaucrat::GradeTooHighException& e)
    {
       std::cout << "range 1-150" << std::endl;
       std::cout << "try again " << std::endl;
    }
    
    */
}
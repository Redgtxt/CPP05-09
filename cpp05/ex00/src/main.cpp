#include "Bureaucrat.hpp"
 
int main()
{
    try
    {
        std::string grade;
        std::getline(std::cin,grade);
        int num = atoi(grade.c_str());
        Bureaucrat z1("Joe",num);
    }
    catch(int grade)
    {
       std::cout << "range 1-150" << std::endl;
       std::cout << "try again " << std::endl;
    }
    



}
#include "RobotomyRequestForm.hpp"
#include <cstdlib>  // para rand()
#include <ctime>    // para time() - se usares srand no main


RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm",72,45)
{
    std::cout << "Default RobotomyRequestForm called without target" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& Target) : AForm("RobotomyRequestForm",72,45)
{
    target = Target;
    std::cout << "Constructor of RobotomyRequestForm with target: " << getTarget() << " created"  << std::endl;
}



RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "Copy assignment RobotomyRequestForm operator called" << std::endl;

    if(this != &other)
    {
        target = other.getTarget();
    }
    
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = obj;
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!this->getSigned())
    {
        throw(FormNotSignedExeption());
    }

    if (executor.getGrade() > this->getExecuteGrade())
    {
        throw(GradeTooLowExeption());
    }

    std::cout << "* drilling noises *" << std::endl;
    
    /*
    50% chance de sucesso 
    ou vai dar 1 ou 0
    */
    if (rand() % 2)
    {
        std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
    }
    else
    {
        std::cout << this->getTarget() << " robotomy failed" << std::endl;
    }
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}
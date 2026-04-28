#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm",25,5)
{
    std::cout << "Default PresidentialPardonForm called without target" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& Target) : AForm("PresidentialPardonForm",25,5)
{
    target = Target;
    std::cout << "Constructor of PresidentialPardonForm with target: " << getTarget() << " created"  << std::endl;
}



PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "Copy assignment PresidentialPardonForm operator called" << std::endl;

    if(this != &other)
    {
        target = other.getTarget();
    }
    
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = obj;
}

//Informs that <target> has been pardoned by Zaphod Beeblebrox
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
  
    if(!this->getSigned())
    {
        throw(FormNotSignedExeption());
    }

    if(executor.getGrade() > this->getExecuteGrade())
    {
        throw(GradeTooLowExeption());
    }

   std::cout << "Target: " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &obj)
{
    *this = obj;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
    if (this != &other)
        (void)other;
    return (*this);
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(std::string& name_form, std::string& target_form) const
{
    std::string forms[] = {"Shrubbery Creation", "Robotomy Request", "Presidential Pardon"};
    
    int i = 0;
    while (i < 3 && name_form != forms[i])
    {
        i++;
    }

    AForm *form = NULL;
    switch (i)
    {
        case 0:
            form = new ShrubberyCreationForm(target_form);
            break;
        case 1:
            form = new RobotomyRequestForm(target_form);
            break;
        case 2:
            form = new PresidentialPardonForm(target_form);
            break;
        default:
            std::cout << "Error: Form '" << name_form << "' does not exist" << std::endl;
            return (NULL);
    }

    std::cout << "Intern creates " << form->getName() << std::endl;
    return form;
}

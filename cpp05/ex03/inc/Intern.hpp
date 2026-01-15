#pragma once
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
    /* data */
public:
    Intern();
    Intern(Intern const &obj);
    Intern& operator=(Intern const &other);
    ~Intern();
    AForm *makeForm(std::string& name_form, std::string& target_form) const;
};

#pragma once
#include "AForm.hpp"

/*
PresidentialPardonForm: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox
*/

class PresidentialPardonForm : public AForm
{

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string& Target);//Constructor
    PresidentialPardonForm(const PresidentialPardonForm &obj);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    void execute(Bureaucrat const & executor) const;
    ~PresidentialPardonForm();
};



#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string& Target);//Constructor
    PresidentialPardonForm(const PresidentialPardonForm &obj);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    void execute(Bureaucrat const & executor) const;
    ~PresidentialPardonForm();
};


#endif
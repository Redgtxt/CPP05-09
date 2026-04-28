#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

/*
ShrubberyCreationForm: Required grades: sign 145, exec 137
Creates a file <target>_shrubbery in the working directory and writes ASCII trees
inside it.
*/

class ShrubberyCreationForm : public AForm
{

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string& Target);//Constructor
    ShrubberyCreationForm(const ShrubberyCreationForm &obj);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
    void execute(Bureaucrat const & executor) const;
    ~ShrubberyCreationForm();
};
#endif

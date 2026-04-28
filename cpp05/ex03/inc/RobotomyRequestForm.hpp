#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

/*
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed
*/

class RobotomyRequestForm : public AForm
{
private:

public:
    RobotomyRequestForm(void);
    RobotomyRequestForm(const std::string& Target);//Constructor
    RobotomyRequestForm(const RobotomyRequestForm &obj);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    void execute(Bureaucrat const & executor) const;
    ~RobotomyRequestForm();
};



#endif
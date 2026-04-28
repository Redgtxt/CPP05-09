#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm",145,137)
{
    std::cout << "Default ShrubberyCreationForm called without target" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& Target) : AForm("ShrubberyCreationForm",145,137)
{
    target = Target;
    std::cout << "Constructor of ShrubberyCreationForm with target: " << getTarget() << " created"  << std::endl;
}



ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "Copy assignment ShrubberyCreationForm operator called" << std::endl;

    if(this != &other)
    {
        target = other.getTarget();
    }
    
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = obj;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
  
    if(!this->getSigned())
    {
        throw(FormNotSignedExeption());
    }

    if(executor.getGrade() > this->getExecuteGrade())
    {
        throw(GradeTooLowExeption());
    }

    std::ofstream file;
    std::string fileName;

    fileName = this->target + "_shrubbery";
    
    file.open(fileName.c_str());
    if(!file.is_open()) 
    {
        std::cout << "Something happened while creating the file" << std::endl;
        return;
    }

    file << "       *\n"
         << "      / \\\n"
         << "     /   \\\n"
         << "    /     \\\n"
         << "   /       \\\n"
         << "  /_________\\\n"
         << "      | |\n";
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}
#include "AForm.hpp"

AForm::AForm() : _name("unknown"), _signGrade(150),_signed(false),_executeGrade(150)
{

    std::cout << "Defautl Form constructor called";
}


AForm::AForm(const std::string& name, int grade,int executeGrade) : _name(name), _signGrade(grade),_signed(false),_executeGrade(executeGrade)
{
    if(grade > 150)
        throw(GradeTooHighExeption());
    if(grade < 1)
        throw(GradeTooLowExeption());
    std::cout << "Constructor called";
}

AForm& AForm::operator=(const AForm& other)
{
    std::cout << "Copy assignment Form operator called" << std::endl;

    if(this != &other)
    {
        _signed = other.getSigned();
    }
    
    return *this;
}

const char* AForm::GradeTooHighExeption::what() const throw()
{
    return "Grade too high";
} 

const char* AForm::GradeTooLowExeption::what() const throw()
{
    return "Grade Too low";
} 

const char* AForm::FormNotSignedExeption::what() const throw()
{
    return "Form not signed";
} 

AForm::AForm(const AForm &obj) : _name(obj.getName()),_signGrade(obj.getSignGrade()), _signed(obj.getSigned()),_executeGrade(obj.getExecuteGrade())
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = obj;
}

void AForm::beSigned(Bureaucrat& z1)
{
    if(z1.getGrade() <= this->_signGrade)
    {
        this->_signed = true;
        std::cout << "Form is now signed, status: " << this->getSigned() << std::endl;
    }else{
        throw(AForm::GradeTooLowExeption());
    }
}

std::string AForm::getName() const
{
    return _name;
}

std::string AForm::getTarget() const
{
    return target;
}

bool AForm::getSigned() const{
    return _signed;
}

int AForm::getSignGrade() const{
    return _signGrade;
}

int AForm::getExecuteGrade() const{
    return _executeGrade;
}

std::ostream &operator<<(std::ostream &out, AForm const &source)
{
	out << source.getName() << " , Form grade " << source.getSignGrade() << "is it signed: " << source.getSigned() << " ExecuteGrade " << source.getExecuteGrade() << std::endl;
	return (out);
}

AForm::~AForm()
{
    std::cout << "Form destructor called" << std::endl;
}

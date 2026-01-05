#include "Form.hpp"

Form::Form() : _name("unknown"), _grade(150),_signed(false),_executeGrade(150)
{

    std::cout << "Defautl Form constructor called";
}


Form::Form(std::string& name, int grade,int executeGrade) : _name(name), _grade(grade),_signed(false),_executeGrade(executeGrade)
{
    if(grade > 150)
        throw(GradeTooHighExeption());
    if(grade < 1)
        throw(GradeTooLowExeption());
    std::cout << "Constructor called";
}

Form& Form::operator=(const Form& other)
{
    std::cout << "Copy assignment Form operator called" << std::endl;

    if(this != &other)
    {
        _signed = other.getSigned();
    }
    
    return *this;
}

const char* Form::GradeTooHighExeption::what() const throw()
{
    return "Too high";
} 

const char* Form::GradeTooLowExeption::what() const throw()
{
    return "Too low";
} 
Form::Form(const Form &obj) : _name(obj.getName()), _signed(obj.getSigned()),_grade(obj.getGrade()),_executeGrade(obj.getExecuteGrade())
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = obj;
}

void Form::beSigned(Bureaucrat& z1)
{
    if(z1.getGrade() >= this->_executeGrade)
    {
        this->_signed = true;
        std::cout << "Form is now signed, status: " << this->getSigned() << std::endl;
    }
}

const std::string& Form::getName() const
{
    return _name;
}

const bool Form::getSigned() const{
    return _signed;
}

const int Form::getGrade() const{
    return _grade;
}

const int Form::getExecuteGrade() const{
    return _executeGrade;
}

std::ostream &operator<<(std::ostream &out, Form const &source)
{
	out << source.getName() << " , Form grade " << source.getGrade() << "is it signed: " << source.getSigned() << " ExecuteGrade " << source.getExecuteGrade() << std::endl;
	return (out);
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

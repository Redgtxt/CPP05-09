#include "Form.hpp"

Form::Form() : _name("unknown"), _SignGrade(150),_signed(false),_executeGrade(150)
{

    std::cout << "Default Form constructor called";
}


Form::Form(const std::string& name, int grade,int executeGrade) : _name(name), _SignGrade(grade),_signed(false),_executeGrade(executeGrade)
{
    if(grade > 150)
        throw(GradeTooLowExeption());
    if(grade < 1)
        throw(GradeTooHighExeption());
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
    return "Grade too high";
} 

const char* Form::GradeTooLowExeption::what() const throw()
{
    return "Grade Too low";
} 
Form::Form(const Form &obj) : _name(obj.getName()),_SignGrade(obj.getSignGrade()), _signed(obj.getSigned()),_executeGrade(obj.getExecuteGrade())
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = obj;
}



void Form::beSigned(Bureaucrat& z1)
{
    
    if(z1.getGrade() <= this->_SignGrade)
    {
        this->_signed = true;
        std::cout << "Form is now signed, status: " << this->getSigned() << std::endl;
    }else{
        throw(Form::GradeTooLowExeption());
    }
}

const std::string& Form::getName() const
{
    return _name;
}

bool Form::getSigned() const{
    return _signed;
}

int Form::getSignGrade() const{
    return _SignGrade;
}

int Form::getExecuteGrade() const{
    return _executeGrade;
}

std::ostream &operator<<(std::ostream &out, Form const &source)
{
	out << source.getName() << ", Form grade " << source.getSignGrade() << "is it signed: " << source.getSigned() << " ExecuteGrade " << source.getExecuteGrade() << std::endl;
	return (out);
}

Form::~Form()
{
    std::cout << "Form destructor called" << std::endl;
}

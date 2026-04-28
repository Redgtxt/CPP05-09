#include "Form.hpp"

//Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name,int grade) : _name(name) ,_grade(grade)
{
    if(grade > 150)
        throw(GradeTooLowException());
    else if(grade < 1)
        throw(GradeTooHighException());
    std::cout << " Bureaucrat with name " << this->getName() <<" and grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "Copy assignment Bureaucrat operator called" << std::endl;

    if(this != &other)
    {
        _grade = other.getGrade();
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called" << std::endl;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

const std::string& Bureaucrat::getName() const
{
    return this->_name;
}

void Bureaucrat::incrementGrade()
{
    if(_grade <= 1)
        throw(GradeTooHighException());
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if(_grade >= 150)
        throw(GradeTooLowException());
    this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
       form.beSigned(*this);
       std::cout << *this << "signed the form" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << *this << "couldn't signed the following the form" << form << std::endl;
        std::cout << e.what() << std::endl;
    }
}


std::ostream &operator<<(std::ostream &out, Bureaucrat const &source)
{
	out << source.getName() << ", bureaucrat grade " << source.getGrade() << std::endl;
	return (out);
}
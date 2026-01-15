
#include "AForm.hpp"

Bureaucrat::Bureaucrat(int grade) : _name("Unkowned") ,_grade(grade)
{
    std::cout << " Bureaucrat with name " << this->getName() <<" and grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name,int grade) : _name(name) ,_grade(grade)
{
    if(grade > 150)
        throw(GradeTooHighException());
    else if(grade < 1)
        throw(GradeTooLowException());
    std::cout << " Bureaucrat with name " << this->getName() <<" and grade " << this->getGrade() << std::endl;
}
int Bureaucrat::getGrade() const
{
    return this->_grade;
}


void Bureaucrat::signForm(AForm &form)
{
    try
    {
       form.beSigned(*this);
       std::cout << *this << "signed the form" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << *this << "couldn't signed the following the form" << form.getName() << std::endl;
        std::cout << e.what() << std::endl;
    }
    
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

Bureaucrat::Bureaucrat(const Bureaucrat &obj)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = obj;
}

const std::string& Bureaucrat::getName() const
{
    return this->_name;
}


//Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called" << std::endl;
}


void Bureaucrat::incrementGrade()
{
    if(_grade <= 1)
        throw(GradeTooHighException());
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if(_grade <= 150)
        throw(GradeTooLowException());
    this->_grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &source)
{
	out << source.getName() << ", bureaucrat grade " << source.getGrade();
	return (out);
}

void Bureaucrat::executeForm(AForm const & form)
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}
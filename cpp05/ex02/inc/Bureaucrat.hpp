#pragma once
#include <iostream>
#include <exception>

class AForm;

/*
    bureaucrat
    [x] const name
    [X] grade range 1-150
        1 e o valor mais alto
        150 o mais baixo

    [x]getName()
    [x]getGrade()
    [x]funcao que incrementa a grade de um bureaucrat
    [x]funcao que decremente a grade de um bureaucrat

    [x] ovrload << que printe <name>, bureaucrat grade <grade>.
*/

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw();
    };

    Bureaucrat(int grade);
    Bureaucrat(const std::string& name,int grade);
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(AForm& form);
    void executeForm(AForm const & form);
};
std::ostream &operator<<(std::ostream &out, Bureaucrat const &source);


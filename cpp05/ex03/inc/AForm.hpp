#pragma once
#include <iostream>
#include <fstream>

class Bureaucrat;

/*
private

    [X]
    A constant name.
    •A boolean indicating whether it is signed (at construction, it is not).
    •A constant grade required to sign it.
    •A constant grade required to execute it.

    [X]
    The grades of the Form follow the same rules as those of the Bureaucrat. Thus, the
    following exceptions will be thrown if a form’s grade is out of bounds:
    Form::GradeTooHighException and Form::GradeTooLowException.

    [X]
    As before, write getters for all attributes and overload the insertion («) operator to
    print all the form’s information.

    [X]
        Also, add a beSigned() member function to the Form that takes a Bureaucrat as a
    parameter. It changes the form’s status to signed if the bureaucrat’s grade is high enough
    (greater than or equal to the required one). Remember, grade 1 is higher than grade 2.
    If the grade is too low, throw a Form::GradeTooLowException.

    [x]
    Then, add a signForm() member function in the Bureaucrat class. This function must
    call Form::beSigned() to attempt to sign the form. If the form is signed successfully, it
    will print something like:
    <bureaucrat> signed <form>
    Otherwise, it will print something like:
    <bureaucrat> couldn’t sign <form> because <reason>.
    Implement and submit some tests to ensure everything works as expected.
11

*/

class AForm
{
private:
    const std::string _name;
    const int _signGrade;
    bool _signed;
    const int _executeGrade;
protected:
    std::string target;
public:

    class GradeTooHighExeption : public std::exception{
        public:
            const char* what() const throw();
    };
    
    class GradeTooLowExeption : public std::exception{
        public:
            const char* what() const throw();
    };

    class FormNotSignedExeption : public std::exception{
        public:
            const char* what() const throw();
    };

    AForm();
    AForm(const std::string& name, int grade,int executeGrade);
    AForm(const AForm &obj);
    AForm& operator=(const AForm& other);
    virtual ~AForm();

    virtual void execute(Bureaucrat const & executor) const = 0;
    void beSigned(Bureaucrat& z1);
    std::string getName() const;
    std::string getTarget() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
};
std::ostream &operator<<(std::ostream &out, AForm const &source);

#include "Bureaucrat.hpp"

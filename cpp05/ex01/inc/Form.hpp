#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    const int _SignGrade;
    bool _signed;
    const int _executeGrade;
public:

    class GradeTooHighExeption : public std::exception{
        public:
            const char* what() const throw();
    };
    
    class GradeTooLowExeption : public std::exception{
        public:
            const char* what() const throw();
    };

    Form();
    Form(const std::string& name, int _SignGrade,int executeGrade);
    Form(const Form &obj);
    Form& operator=(const Form& other);
    ~Form();

    void beSigned(Bureaucrat& z1);
    const std::string& getName() const;
    bool getSigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;
};
std::ostream &operator<<(std::ostream &out, Form const &source);
#endif

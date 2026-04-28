#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <fstream>

class Bureaucrat;

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
#endif

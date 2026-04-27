#include <iostream>
#include <exception>
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

class AForm;


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

    Bureaucrat(void);
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

#endif
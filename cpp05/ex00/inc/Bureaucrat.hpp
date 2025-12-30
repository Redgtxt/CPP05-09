#include <iostream>
#include <exception>

/*
    bureaucrat
    [x] const name
    [] const grade range 1-150
        1 e o valor mais alto
        150 o mais baixo

    [x]getName()
    [x]getGrade()
    []funcao que incrementa a grade de um bureaucrat
    []funcao que decremente a grade de um bureaucrat

    []ovrload << que printe <name>, bureaucrat grade <grade>.
*/

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };

    Bureaucrat(int grade);
    Bureaucrat(std::string name,int grade);
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();
    const std::string& getName() const;
    int getGrade() const;
};


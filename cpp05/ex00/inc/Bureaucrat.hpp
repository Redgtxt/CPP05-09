#include <iostream>

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
    //Bureaucrat();
    Bureaucrat(std::string name,int grade);
    Bureaucrat(int grade);
    Bureaucrat(const Bureaucrat &obj);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string& getName() const;
    int getGrade() const;
};

Bureaucrat::Bureaucrat(int grade) : _name("Unkowned") ,_grade(grade)
{
    std::cout << "Bureaucrat with name " << this->getName() <<" and grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string name,int grade) : _name(name) ,_grade(grade)
{
    std::cout << "Bureaucrat with name " << this->getName() <<" and grade " << this->getGrade() << std::endl;
}
int Bureaucrat::getGrade() const
{
    return this->_grade;
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

const std::string& Bureaucrat::getName() 
const
{
    return this->_name;
}



Bureaucrat::~Bureaucrat()
{
    std::cout << "destructor called" << std::endl;
}

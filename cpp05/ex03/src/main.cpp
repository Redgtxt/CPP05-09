#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>
#include <cstdlib>

void testInternMakeForm()
{
    std::cout << "\n========== TEST INTERN MAKE FORM ==========\n" << std::endl;
    
    Intern someRandomIntern;
    AForm* form;

    // Test 1: Criar RobotomyRequestForm (exemplo do subject)
    std::cout << "\n--- Test 1: Criar RobotomyRequestForm ---" << std::endl;
    form = someRandomIntern.makeForm("Robotomy Request", "Bender");
    if (form)
    {
        std::cout << "Form created: " << form->getName() << " with target: " << form->getTarget() << std::endl;
        delete form;
    }

    // Test 2: Criar ShrubberyCreationForm
    std::cout << "\n--- Test 2: Criar ShrubberyCreationForm ---" << std::endl;
    std::string formName2 = "Shrubbery Creation";
    std::string target2 = "garden";
    form = someRandomIntern.makeForm("Shrubbery Creation", target2);
    if (form)
    {
        std::cout << "Form created: " << form->getName() << " with target: " << form->getTarget() << std::endl;
        delete form;
    }

    // Test 3: Criar PresidentialPardonForm
    std::cout << "\n--- Test 3: Criar PresidentialPardonForm ---" << std::endl;
    std::string formName3 = "Presidential Pardon";
    std::string target3 = "Arthur Dent";
    form = someRandomIntern.makeForm(formName3, target3);
    if (form)
    {
        std::cout << "Form created: " << form->getName() << " with target: " << form->getTarget() << std::endl;
        delete form;
    }

    // Test 4: Form inexistente
    std::cout << "\n--- Test 4: Form inexistente ---" << std::endl;
    std::string formName4 = "Invalid Form";
    std::string target4 = "nobody";
    form = someRandomIntern.makeForm(formName4, target4);
    if (form)
    {
        std::cout << "Form created: " << form->getName() << std::endl;
        delete form;
    }
    else
    {
        std::cout << "Form was not created (returned NULL)" << std::endl;
    }
}

void testInternWithBureaucrat()
{
    std::cout << "\n========== TEST INTERN WITH BUREAUCRAT ==========\n" << std::endl;

    Intern intern;
    Bureaucrat boss("Boss", 1);
    AForm* form;

    // Intern cria um form, Bureaucrat assina e executa
    std::cout << "\n--- Intern cria RobotomyRequestForm ---" << std::endl;
    std::string formName = "Robotomy Request";
    std::string target = "Fry";
    form = intern.makeForm(formName, target);

    if (form)
    {
        std::cout << "\n--- Bureaucrat assina o form ---" << std::endl;
        boss.signForm(*form);

        std::cout << "\n--- Bureaucrat executa o form ---" << std::endl;
        boss.executeForm(*form);

        delete form;
    }

    // Test com PresidentialPardonForm
    std::cout << "\n--- Intern cria PresidentialPardonForm ---" << std::endl;
    std::string formName2 = "Presidential Pardon";
    std::string target2 = "Marvin";
    form = intern.makeForm(formName2, target2);

    if (form)
    {
        std::cout << "\n--- Bureaucrat assina e executa ---" << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;
    }

    // Test com ShrubberyCreationForm
    std::cout << "\n--- Intern cria ShrubberyCreationForm ---" << std::endl;
    std::string formName3 = "Shrubbery Creation";
    std::string target3 = "office";
    form = intern.makeForm(formName3, target3);



    if (form)
    {
        std::cout << "\n--- Bureaucrat assina e executa ---" << std::endl;
        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;
    }
}

int main()
{
    srand(time(0));

    testInternMakeForm();
    testInternWithBureaucrat();

    std::cout << "\n========== FIM DOS TESTES ==========\n" << std::endl;

    return 0;
}
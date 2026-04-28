#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>
#include <cstdlib>

void testShrubberyCreationForm()
{
    std::cout << "\n========== TEST SHRUBBERY CREATION FORM ==========\n" << std::endl;
    
    try
    {
        std::string target = "home";
        Bureaucrat bob("Bob", 130);  // Grade suficiente para assinar (145) e executar (137)
        Bureaucrat lowGrade("LowGuy", 150);
        ShrubberyCreationForm shrub(target);

        std::cout << "\n--- Test 1: Executar sem assinar ---" << std::endl;
        bob.executeForm(shrub);

        std::cout << "\n--- Test 2: Bureaucrat com grade baixo tenta assinar ---" << std::endl;
        lowGrade.signForm(shrub);

        std::cout << "\n--- Test 3: Bureaucrat com grade suficiente assina ---" << std::endl;
        bob.signForm(shrub);

        std::cout << "\n--- Test 4: Executar formulario assinado ---" << std::endl;
        bob.executeForm(shrub);

        std::cout << "\n--- Test 5: Bureaucrat com grade baixo tenta executar ---" << std::endl;
        Bureaucrat weak("WeakGuy", 145);
        weak.executeForm(shrub);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testRobotomyRequestForm()
{
    std::cout << "\n========== TEST ROBOTOMY REQUEST FORM ==========\n" << std::endl;

    try
    {
        std::string target = "Bender";
        Bureaucrat alice("Alice", 40);
        Bureaucrat lowGrade("LowGuy", 100);
        RobotomyRequestForm robot(target);
        Bureaucrat God("God", 1);

        for(int i = 0; i < 50; i ++)
        {
        std::string target = "Xuxu";

        RobotomyRequestForm xuxu(target);
        xuxu.beSigned(God);
        xuxu.execute(God);
             

        }
        std::cout << "\n--- Test 1: Executar sem assinar ---" << std::endl;
        alice.executeForm(robot);

        std::cout << "\n--- Test 2: Bureaucrat com grade baixo tenta assinar ---" << std::endl;
        lowGrade.signForm(robot);

        std::cout << "\n--- Test 3: Bureaucrat com grade suficiente assina ---" << std::endl;
        alice.signForm(robot);

        std::cout << "\n--- Test 4: Executar formulario assinado (50% chance) ---" << std::endl;
        alice.executeForm(robot);

        std::cout << "\n--- Test 5: Executar mais vezes para ver 50% chance ---" << std::endl;
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Tentativa " << i + 1 << ": ";
            alice.executeForm(robot);
        }

        std::cout << "\n--- Test 6: Bureaucrat com grade baixo tenta executar ---" << std::endl;
        lowGrade.executeForm(robot);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testPresidentialPardonForm()
{
    std::cout << "\n========== TEST PRESIDENTIAL PARDON FORM ==========\n" << std::endl;

    try
    {
        std::string target = "Arthur Dent";
        Bureaucrat president("President", 1);
        Bureaucrat midGrade("MidGuy", 20);
        Bureaucrat lowGrade("LowGuy", 50);
        PresidentialPardonForm pardon(target);

        std::cout << "\n--- Test 1: Executar sem assinar ---" << std::endl;
        president.executeForm(pardon);

        std::cout << "\n--- Test 2: Bureaucrat com grade baixo tenta assinar ---" << std::endl;
        lowGrade.signForm(pardon);

        std::cout << "\n--- Test 3: Bureaucrat com grade suficiente assina ---" << std::endl;
        midGrade.signForm(pardon);

        std::cout << "\n--- Test 4: Bureaucrat com grade baixo tenta executar ---" << std::endl;
        midGrade.executeForm(pardon);

        std::cout << "\n--- Test 5: President executa o perdao ---" << std::endl;
        president.executeForm(pardon);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }
}

void testExceptions()
{
    std::cout << "\n========== TEST EXCEPTIONS ==========\n" << std::endl;

    std::cout << "--- Test: Criar Bureaucrat com grade invalido ---" << std::endl;
    try
    {
        Bureaucrat invalid("Invalid", 0);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat invalid("Invalid", 151);
    }
    catch (std::exception& e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
}

int main()
{
    srand(time(0));

    testShrubberyCreationForm();
    testRobotomyRequestForm();
    testPresidentialPardonForm();
    testExceptions();

    std::cout << "\n========== FIM DOS TESTES ==========\n" << std::endl;

    return 0;
}
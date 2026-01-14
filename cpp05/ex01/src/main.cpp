#include "Form.hpp"

int main()
{
	std::cout << "\n===== Form success tests =====\n"
			  << std::endl;

	try
	{
		Form success("Success", 50, 10);
		Bureaucrat joao("Joao", 3);

		joao.signForm(success);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n===== Form Exception tests =====\n"
			  << std::endl;
	try
	{

		Form test("A normal form", 50, 10);
		Bureaucrat testfail("Failing", 100);

		std::cout << test;

		testfail.signForm(test);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "\n===== Form grade too low tests =====\n"
			  << std::endl;

	try
	{
		Form fail("fail", 200, 10);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
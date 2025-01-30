#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat basic("Paul", 42);
	Bureaucrat high("Boss", 1);
	Bureaucrat low("Intern", 150);
	std::cout << "--------------------------------------------" << std::endl;
	Form highForm("Important Form", 1, 1);
	Form lowForm("Unimportant Form", 150, 150);
	
	std::cout << "--------------------------------------------" << std::endl;
	std::cout << basic << std::endl << high << std::endl << low << std::endl;
	std::cout << highForm << std::endl << lowForm << std::endl;
	/*
	std::cout << "--------------------------------------------" << std::endl;
	Form copyForm(lowForm); // Testing copy constructor
	std::cout << copyForm << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	// Testing construction with invalid grades (< 1)
	try
	{
		Form c("Bad signature grade", 0, 42);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form d("Bad execution grade", 42, 0);
		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
	// Testing construction with invalid grades (> 150)
	try
	{
		Form c("Bad signature grade", 151, 42);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form d("Bad execution grade", 42, 151);
		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	*/
	std::cout << "--------------------------------------------" << std::endl;
	basic.signForm(highForm); // doesn't work, GradeTooLowException
	high.signForm(highForm); // should work, grade is high enough
	std::cout << "--------------------------------------------" << std::endl;
	low.signForm(lowForm); // should work
	high.signForm(lowForm); // doesn't work, AlreadySignedException
	std::cout << "--------------------------------------------" << std::endl;
	/*
	// Testing copy assignment operator
	std::cout << "Before copy assignment operator: " << copyForm << std::endl;
	copyForm = lowForm;
	std::cout << "After copy assignment operator: " << copyForm << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	*/
	return (0);
}
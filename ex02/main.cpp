#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat basic("Paul", 42);
	Bureaucrat high("High", 2);
	Bureaucrat low("Low", 149);
	std::cout << "--------------------------------------------" << std::endl;
	AForm *shrub = new ShrubberyCreationForm("home");
	basic.signAForm(*shrub);
	shrub->execute(basic);
	/*
	std::cout << "--------------------------------------------" << std::endl;
	// Testing insertion operator overload <<
	std::cout << lowAForm << std::endl;
	std::cout << highAForm << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	AForm copyAForm(lowAForm); // Testing copy constructor
	std::cout << copyAForm << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	// Testing construction with invalid grades (< 1)
	try
	{
		AForm c("Bad signature grade", 0, 42);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		AForm d("Bad execution grade", 42, 0);
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
		AForm c("Bad signature grade", 151, 42);
		std::cout << c << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		AForm d("Bad execution grade", 42, 151);
		std::cout << d << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
	basic.signAForm(highAForm); // doesn't work, GradeTooLowException
	high.signAForm(highAForm); // should work, grade is high enough
	std::cout << "--------------------------------------------" << std::endl;
	// Testing signAForm for double signature
	low.signAForm(lowAForm); // should work
	high.signAForm(lowAForm); // doesn't work, AlreadySignedException
	std::cout << "--------------------------------------------" << std::endl;
	// Testing copy assignment operator
	std::cout << "Before copy assignment operator: " << copyAForm << std::endl;
	copyAForm = lowAForm;
	std::cout << "After copy assignment operator: " << copyAForm << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	*/
	return (0);
}
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat basic("Paul", 42);
	Bureaucrat low("Low Test", 149);
	Bureaucrat high("High Test", 2);
	std::cout << basic << std::endl << low << std::endl << high << std::endl;
	try
	{
		Bureaucrat a(0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b(151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		low.decrementGrade();
		std::cout << low << std::endl;
		low.decrementGrade();
		std::cout << low << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		high.incrementGrade();
		std::cout << high << std::endl;
		high.incrementGrade();
		std::cout << high << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat basic("Paul", 42);
	Bureaucrat high("High", 2);
	Bureaucrat low("Low", 149);
	std::cout << "--------------------------------------------" << std::endl;
	// Testing insertion operator overload <<
	std::cout << basic << std::endl;
	std::cout << low << std::endl;
	std::cout << high << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	Bureaucrat copy(low); // Testing copy constructor
	std::cout << copy << std::endl;
	copy = basic; // Testing copy assignment operator
	std::cout << copy << std::endl;
	std::cout << "--------------------------------------------" << std::endl;
	// Testing construction with invalid grade (< 1)
	try
	{
		Bureaucrat a(0);
		std::cout << a << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
	// Testing construction with invalid grade (> 150)
	try
	{
		Bureaucrat b(151);
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------" << std::endl;
	// Testing increment function until invalid grade (< 1)
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
	std::cout << "--------------------------------------------" << std::endl;
	// Testing decrement function until invalid grade (> 150)
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
	std::cout << "--------------------------------------------" << std::endl;
	return (0);
}
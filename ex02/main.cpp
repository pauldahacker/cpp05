#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat basic("Paul", 46);
	Bureaucrat high("High", 6);
	Bureaucrat low("Low", 138);
	std::cout << "--------------------------------------------" << std::endl;
	AForm *shrub = new ShrubberyCreationForm("home");
	std::cout << "Testing execution with: " << low << std::endl;
	low.executeForm(*shrub);
	low.signForm(*shrub);
	low.executeForm(*shrub);
	low.incrementGrade();
	std::cout << low << std::endl;
	low.executeForm(*shrub);
	delete shrub;
	std::cout << "--------------------------------------------" << std::endl;
	AForm *robo = new RobotomyRequestForm("Bruce Lee");
	std::cout << "Testing execution with: " << basic << std::endl;
	basic.executeForm(*robo);
	basic.signForm(*robo);
	basic.executeForm(*robo);
	basic.incrementGrade();
	std::cout << basic << std::endl;
	std::cout << "Testing 50% robotomy success: " << std::endl;
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "[" << i << "] ";
		basic.executeForm(*robo);
	}
	delete robo;
	std::cout << "--------------------------------------------" << std::endl;
	AForm *pres = new PresidentialPardonForm("Tiger King");
	std::cout << "Testing execution with: " << high << std::endl;
	high.executeForm(*pres);
	high.signForm(*pres);
	high.executeForm(*pres);
	high.incrementGrade();
	std::cout << high << std::endl;
	high.executeForm(*pres);
	delete pres;
	std::cout << "--------------------------------------------" << std::endl;
	return (0);
} 
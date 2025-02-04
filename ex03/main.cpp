#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;

	std::cout << "--------------------------------------------" << std::endl;
	AForm *shrub;
	shrub = someRandomIntern.makeForm("shrubbery creation", "Bender");
	std::cout << "--------------------------------------------" << std::endl;
	AForm *robo;
	robo = someRandomIntern.makeForm("robotomy request", "Bender");
	std::cout << "--------------------------------------------" << std::endl;
	AForm *pres;
	pres = someRandomIntern.makeForm("presidential pardon", "Bender");
	std::cout << "--------------------------------------------" << std::endl;
	AForm *bad;
	bad = someRandomIntern.makeForm("Classified", "Bender");
	std::cout << "--------------------------------------------" << std::endl;
	delete shrub;
	delete robo;
	delete pres;
	delete bad;
	return (0);
} 
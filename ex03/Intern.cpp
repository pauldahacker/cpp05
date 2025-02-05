#include "Intern.hpp"

class Intern::FormDoesNotExistException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Form does not exist!");
		}
};


Intern::Intern(void)
{
	std::cout << "Default Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Copy Intern constructor called" << std::endl;
	*this = other;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

const Intern &Intern::operator=(const Intern &other)
{
	(void) other;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	int index = 0;
	std::string formList[N_FORMS] =
		{SHRUBBERY_CREATION_STR, ROBOTOMY_REQUEST_STR, PRESIDENTIAL_PARDON_STR};

	while (index < N_FORMS && name != formList[index])
		++index;
	switch (index)
	{	
		case (0):
			std::cout << "Intern creates <" << name << " form>." << std::endl;
			return new ShrubberyCreationForm(target);
		case (1):
			std::cout << "Intern creates <" << name << " form>." << std::endl;
			return new RobotomyRequestForm(target);
		case (2):
			std::cout << "Intern creates <" << name << " form>." << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cerr << "Intern couldn't create <" << name
				<< ">. Form does not exist!" << std::endl;
			return (NULL);
	}
}
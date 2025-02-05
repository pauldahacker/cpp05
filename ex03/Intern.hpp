#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

# define SHRUBBERY_CREATION_STR "shrubbery creation"
# define PRESIDENTIAL_PARDON_STR "presidential pardon"
# define ROBOTOMY_REQUEST_STR "robotomy request"
# define N_FORMS 3

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		~Intern(void);

		const Intern &operator=(const Intern &other);

		// Form Creation Exception
		class FormDoesNotExistException;
		// Member function
		AForm *makeForm(std::string name, std::string target);
	private:
		void searchForm(std::string name);
};

#endif
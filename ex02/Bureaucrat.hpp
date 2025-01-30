#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include "AForm.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(int grade);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat();

		const Bureaucrat &operator=(const Bureaucrat &other);

		// Exceptions
		class GradeTooHighException;
		class GradeTooLowException;
		// Member functions
		std::string getName(void) const;
		int getGrade(void) const;
		void incrementGrade(void);
		void decrementGrade(void);
		void signAForm(AForm &AForm) const;
	private:
		const std::string _name;
		int	_grade;
};

// insertion operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat);

#endif
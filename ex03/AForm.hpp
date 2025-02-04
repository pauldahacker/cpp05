#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(const int signGrade, const int execGrade);
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &other);
		virtual ~AForm();

		const AForm &operator=(const AForm &other);

		// Signature Exceptions
		class GradeTooHighException;
		class GradeTooLowException;
		class AlreadySignedException;
		// Execution Exceptions
		class NotSignedException;
		class ExecGradeTooLowException;
		// Form Creation Exceptions
		class FormDoesNotExistException;
		// Member functions
		std::string getName(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat &bureaucrat);
		void beExecuted(const Bureaucrat &executor) const;
		// Abstract function
		virtual void execute(const Bureaucrat &executor) const = 0;

	private:
		const std::string _name;
		bool	_signed;
		const int	_signGrade;
		const int	_execGrade;
};

// insertion operator overload
std::ostream& operator<<(std::ostream& out, const AForm &AForm);

#endif
#ifndef Form_HPP
# define Form_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(const int signGrade, const int execGrade);
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form &other);
		virtual ~Form();

		const Form &operator=(const Form &other);

		// Signature Exceptions
		class GradeTooHighException;
		class GradeTooLowException;
		class AlreadySignedException;
		// Execution Exceptions
		class NotSignedException;
		class ExecGradeTooLowException;
		// Member functions
		std::string getName(void) const;
		bool getSigned(void) const;
		int getSignGrade(void) const;
		int getExecGrade(void) const;
		void beSigned(const Bureaucrat &bureaucrat);

	private:
		const std::string _name;
		bool	_signed;
		const int	_signGrade;
		const int	_execGrade;
};

// insertion operator overload
std::ostream& operator<<(std::ostream& out, const Form &Form);

#endif
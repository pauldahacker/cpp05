#include "AForm.hpp"

class AForm::GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too high!");
		}
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too low!");
		}
};

class AForm::AlreadySignedException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Form has already been signed!");
		}
};

class AForm::NotSignedException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Form has not been signed!");
		}
};

class AForm::ExecGradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Execution grade too low!");
		}
};

AForm::AForm(const int signGrade, const int execGrade) : _name("Default"),
	_signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw (GradeTooHighException());
	std::cout << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : 
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw (GradeTooHighException());
	std::cout << "AForm constructor called for: " << _name << std::endl;
}

AForm::AForm(const AForm &other) : _name(other.getName()),
	_signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
	std::cout << "Copy AForm constructor called for: " << _name << std::endl;
	*this = other;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called for: " << _name << std::endl;
}

const AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		_signed = other.getSigned();
	return (*this);
}

std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSigned(void) const
{
	return (_signed);
}

int AForm::getSignGrade(void) const
{
	return (_signGrade);
}

int AForm::getExecGrade(void) const
{
	return (_execGrade);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
		throw (AlreadySignedException());
	else if (bureaucrat.getGrade() <= _signGrade)
	{
		_signed = true;
		std::cout << "Bureaucrat <" << bureaucrat.getName()
			<< "> signed Form <" << _name << ">." << std::endl;
	}
	else
		throw (GradeTooLowException());
}

void AForm::beExecuted(Bureaucrat const & executor) const
{
	if (!_signed)
		throw (NotSignedException());
	else if (executor.getGrade() > _execGrade)
		throw (ExecGradeTooLowException());
	else
		std::cout << "Bureaucrat <" << executor.getName() \
			<< "> executed Form <" << getName() << ">" << std::endl;
}

std::ostream &operator<<(std::ostream &out, AForm const &AForm)
{
	out << "<" << AForm.getName() << ">, Form is signed <"
		<< AForm.getSigned() << ">, signature grade <"
		<< AForm.getSignGrade() << ">, execution grade <"
		<< AForm.getExecGrade() << ">.";
	return (out);
}
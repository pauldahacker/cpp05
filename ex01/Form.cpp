#include "Form.hpp"

class Form::GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too high!");
		}
};

class Form::GradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too low!");
		}
};

class Form::AlreadySignedException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Form has already been signed!");
		}
};

Form::Form(const int signGrade, const int execGrade) : _name("Default"),
	_signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw (GradeTooHighException());
	std::cout << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : 
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw (GradeTooLowException());
	else if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw (GradeTooHighException());
	std::cout << "Form constructor called for: " << _name << std::endl;
}

Form::Form(const Form &other) : _name(other.getName()),
	_signGrade(other.getSignGrade()), _execGrade(other.getExecGrade())
{
	std::cout << "Copy Form constructor called for: " << _name << std::endl;
	*this = other;
}

Form::~Form()
{
	std::cout << "Form destructor called for: " << _name << std::endl;
}

const Form &Form::operator=(const Form &other)
{
	if (this != &other)
		_signed = other.getSigned();
	return (*this);
}

std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

int Form::getSignGrade(void) const
{
	return (_signGrade);
}

int Form::getExecGrade(void) const
{
	return (_execGrade);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (_signed)
		throw (AlreadySignedException());
	else if (bureaucrat.getGrade() <= _signGrade)
	{
		_signed = true;
		std::cout << "Bureaucrat <" << bureaucrat.getName()
			<< "> signed form <" << _name << ">." << std::endl;
	}
	else
		throw (GradeTooLowException());
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "<" << form.getName() << ">, form is signed <"
		<< form.getSigned() << ">, signature grade <"
		<< form.getSignGrade() << ">, execution grade <"
		<< form.getExecGrade() << ">.";
	return (out);
}
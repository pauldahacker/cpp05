#include "Bureaucrat.hpp"

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too high!");
		}
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too low!");
		}
};

Bureaucrat::Bureaucrat(int grade) : _name("Default"), _grade(grade)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << "Bureaucrat constructor called for: " << _name << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName())
{
	std::cout << "Copy Bureaucrat constructor called" << std::endl;
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called for: " << _name << std::endl;
}

const Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	if (_grade == MAX_GRADE)
		throw GradeTooLowException();
	else
		--_grade;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade == MIN_GRADE)
		throw GradeTooHighException();
	else
		++_grade;
}

void Bureaucrat::signAForm(AForm &AForm) const
{
	try
	{
		AForm.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat <" << _name << "> couldn't sign AForm <"
			<< AForm.getName() << "> because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << "<" << bureaucrat.getName() << ">, bureaucrat grade <"
		<< bureaucrat.getGrade() << ">.";
	return (out);
}

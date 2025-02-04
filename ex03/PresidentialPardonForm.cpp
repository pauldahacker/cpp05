#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) :
	AForm("Presidential Pardon Form", PRESIDENTIAL_PARDON_SIGN, PRESIDENTIAL_PARDON_EXEC), _target("Default")
{
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
}


PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm("Presidential Pardon Form", PRESIDENTIAL_PARDON_SIGN, PRESIDENTIAL_PARDON_EXEC), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called for target: " << _target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : 
	AForm(other), _target(other._target)
{
	std::cout << "Copy PresidentialPardonForm constructor called for target: " << _target << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor called for target: " << _target << std::endl;
}

const PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		beExecuted(executor);
		std::cout << "<" << _target << "> has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

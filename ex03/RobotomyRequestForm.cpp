#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) :
	AForm("Robotomy Request Form", ROBOTOMY_REQUEST_SIGN, ROBOTOMY_REQUEST_EXEC), _target("Default")
{
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
}


RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm("Robotomy Request Form", ROBOTOMY_REQUEST_SIGN, ROBOTOMY_REQUEST_EXEC), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called for target: " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : 
	AForm(other), _target(other._target)
{
	std::cout << "Copy RobotomyRequestForm constructor called for target: " << _target << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor called for target: " << _target << std::endl;
}

const RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    static bool is_successful = true;

	try
	{
		beExecuted(executor);
		if (is_successful)
            std::cout << "<" << _target << "> has been robotomized successfully!" << std::endl;
        else
            std::cout << "<" << _target << "> failed their robotomy..." << std::endl;
        is_successful = !is_successful;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

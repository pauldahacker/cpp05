#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) :
	AForm("Shrubbery Creation Form", SHRUBBERY_CREATION_SIGN, SHRUBBERY_CREATION_EXEC), _target("Default")
{
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
}


ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm("Shrubbery Creation Form", SHRUBBERY_CREATION_SIGN, SHRUBBERY_CREATION_EXEC), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called for: " << getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : 
	AForm(other), _target(other._target)
{
	std::cout << "Copy ShrubberyCreationForm constructor called for: " << getName() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called for: " << getName() << std::endl;
}

const ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->_target = other._target;
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		beExecuted(executor);
		std::string shrubberyName = _target + "_shrubbery";
		std::ofstream shrubbery(shrubberyName.c_str());
		shrubbery << ASCII_PALM_TREE << std::endl;
		shrubbery.close();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

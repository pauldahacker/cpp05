#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

# define ROBOTOMY_REQUEST_SIGN 72
# define ROBOTOMY_REQUEST_EXEC 45

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		const RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		// Member function
		void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif
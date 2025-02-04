#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

# define PRESIDENTIAL_PARDON_SIGN 25
# define PRESIDENTIAL_PARDON_EXEC 5

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		const PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

		// Member function
		void execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};

#endif
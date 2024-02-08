#pragma once

# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:

		std::string	_target;

	public:

		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		const std::string&	getTarget() const;

		void				execute(const Bureaucrat& executor) const;
};

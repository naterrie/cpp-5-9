#pragma once

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class PresidentialPardon : public Form
{
	private:

		const std::string	_target;

	public:

		PresidentialPardon();
		PresidentialPardon(const std::string& target);
		PresidentialPardon(const PresidentialPardon& other);
		~PresidentialPardon();

		PresidentialPardon&	operator=(const PresidentialPardon& other);

		const std::string&	getTarget() const;

		void				execute(const Bureaucrat& executor) const;
};

#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:

		std::string	_target;

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		const std::string&	getTarget() const;

		class FileNotOpenException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		void				execute(const Bureaucrat& executor) const;
};

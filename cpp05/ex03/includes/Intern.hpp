#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:

		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern&	operator=(const Intern& other);

		AForm*	makeForm(const std::string& formName, const std::string& target);
};

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern::~Intern()
{
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

AForm*	makeShrubberyCreationForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	makeRobotomyRequestForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	makePresidentialPardonForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (*forms[3])(const std::string &) = {&makeShrubberyCreationForm, &makeRobotomyRequestForm, &makePresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i](target));
		}
	}
	std::cout << "Intern cannot create " << formName << std::endl;
	return (NULL);
}

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	{
		AForm*	forms[3];

		forms[0] = new ShrubberyCreationForm("home");
		forms[1] = new RobotomyRequestForm("home");
		forms[2] = new PresidentialPardonForm("home");

		for (int i = 0; i < 3; i++)
		{
			std::cout << *forms[i] << std::endl;
			delete forms[i];
		}
	}
	{
		try
		{
			AForm *form = new ShrubberyCreationForm("tree");
			Bureaucrat bureaucrat("bureaucrat", 1);

		std::cout << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			std::cout << std::endl;
			delete form;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			AForm *form = new RobotomyRequestForm("robot");
			Bureaucrat bureaucrat("bureaucrat", 1);
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			std::cout << std::endl;
			delete form;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			AForm *form = new PresidentialPardonForm("president");
			Bureaucrat bureaucrat("bureaucrat", 1);
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

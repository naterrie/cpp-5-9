#include "Intern.hpp"

int main(void)
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		Bureaucrat b("Bender", 1);
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf->beSigned(b);
		rrf->execute(b);
		delete rrf;
	}
	{
		Intern someRandomIntern;
		AForm* rrf[3];
		Bureaucrat a("HaH", 1);
		Bureaucrat b("Bender", 1);
		Bureaucrat c("RushC", 1);
		rrf[0] = someRandomIntern.makeForm("shrubbery creation", "Bender");
		rrf[1] = someRandomIntern.makeForm("robotomy request", "Bender");
		rrf[2] = someRandomIntern.makeForm("presidential pardon", "Bender");
		a.signForm(*rrf[0]);
		b.signForm(*rrf[1]);
		c.signForm(*rrf[2]);
		a.executeForm(*rrf[0]);
		b.executeForm(*rrf[1]);
		c.executeForm(*rrf[2]);
		delete rrf[0];
		delete rrf[1];
		delete rrf[2];
	}
}

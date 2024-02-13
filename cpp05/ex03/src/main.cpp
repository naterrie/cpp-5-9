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
		rrf[0]->beSigned(a);
		rrf[1]->beSigned(b);
		rrf[2]->beSigned(c);
		rrf[0]->execute(a);
		rrf[1]->execute(b);
		rrf[2]->execute(c);

		delete rrf[0];
		delete rrf[1];
		delete rrf[2];
	}
}

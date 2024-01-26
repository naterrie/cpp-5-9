#include "Bureaucrat.cpp"

int main(void)
{
	try
	{
		Bureaucrat b("ElonMusk", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

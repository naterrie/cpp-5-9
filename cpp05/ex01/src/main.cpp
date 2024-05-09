#include "Form.hpp"

int main(void)
{
	std::cout << "test sign to low" << std::endl;
	{
		try
		{
			Form f("Form1", 2, 2);
			Bureaucrat b("ElonMusk", 3);
			b.signForm(f);
			std::cout << f << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "test sign too high" << std::endl;
	{
		try
		{
			Form f("Form2", 0, 150);
			Bureaucrat b("ElonMusk", 149);
			b.signForm(f);
			std::cout << f << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "test signed okay" << std::endl;
	{
		try
		{
			Form f("Form2", 150, 150);
			Bureaucrat b("ElonMusk", 149);
			b.signForm(f);
			std::cout << f << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "test form too low" << std::endl;
	{
		try
		{
			Form f("Form3", 151, 150);
			Bureaucrat b("ElonMusk", 150);
			b.signForm(f);
			std::cout << f << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		try
		{
			Form f("Form3", 150, 150);
			Bureaucrat b("ElonMusk", 150);
			b.signForm(f);
			b.signForm(f);
			std::cout << f << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

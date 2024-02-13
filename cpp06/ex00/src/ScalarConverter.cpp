#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string& input) : _input(input)
{
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert()
{
	_convertChar();
	_convertInt();
	_convertFloat();
	_convertDouble();
}

void	ScalarConverter::_convertChar()
{
	try
	{
		int	c = std::atoi(_input.c_str());
		if (c < 0 || c > 127)
		{
			std::cerr << "char: impossible" << std::endl;
			return ;
		}
		std::cout << "char: '" << static_cast<char>(c) << "'" << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "char: impossible" << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "char: impossible" << std::endl;
	}
}

void	ScalarConverter::_convertInt()
{
	try
	{
		int i = std::atoi(_input.c_str());
		std::cout << "int: " << i << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "int: impossible" << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "int: impossible" << std::endl;
	}
}

void	ScalarConverter::_convertFloat()
{
	try
	{
		_float = std::stof(_input);
		std::cout << "float: " << _float << "f" << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "float: impossible" << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "float: impossible" << std::endl;
	}
}

void	ScalarConverter::_convertDouble()
{
	try
	{
		_double = std::stod(_input);
		std::cout << "double: " << _double << std::endl;
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << "double: impossible" << std::endl;
	}
	catch (std::out_of_range& e)
	{
		std::cerr << "double: impossible" << std::endl;
	}
}

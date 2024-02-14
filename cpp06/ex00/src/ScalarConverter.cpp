#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(const std::string& input) : _input(input)
{
	_char = 0;
	_int = 0;
	_float = 0;
	_double = 0;
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert()
{
	if (_input.empty())
	{
		std::cerr << "Usage: ./convert [value]" << std::endl;
		return;
	}
	if (_input.length() == 1 && !isdigit(_input[0]))
	{
		_convertChar();
		std::cout << "char: " << _char << std::endl;
		std::cout << "int: " << _int << std::endl;
		std::cout << "float: " << _float << std::endl;
		std::cout << "double: " << _double << std::endl;
		return ;
	}
	int i = 0;
	int dot = 0;
	while (_input[i])
	{
		if (isdigit(_input[i]) || _input[i] == '.')
		{
			if (_input[i] == '.')
				dot++;
			i++;
		}
		else if (_input[i] == 'f' || _input[i] == 'e')
		{
			_convertFloat();
			return;
		}
		else
			return ;
	}
	if (dot == 1)
		_convertDouble();
	else if (dot == 0)
		_convertInt();
	else
			return ;
	std::cout << "char: " << _char << std::endl;
	std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}

void	ScalarConverter::_convertChar()
{
	_char = _input[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
}

void	ScalarConverter::_convertInt()
{
	double temp = std::strtod(_input.c_str(), NULL);
	if (temp < std::numeric_limits<int>::min() || temp > std::numeric_limits<int>::max())
	{
		_convertDouble();
		return ;
	}
	_int = std::atoi(_input.c_str());
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void	ScalarConverter::_convertFloat()
{
}

void	ScalarConverter::_convertDouble()
{
}

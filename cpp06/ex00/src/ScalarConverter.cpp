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
		printScalar();
		return ;
	}
	if (_input == "nan" || _input == "nanf" || _input == "+inf" || _input == "+inff" || _input == "-inf" || _input == "-inff")
	{
		_double = std::strtod(_input.c_str(), NULL);
		_float = std::strtof(_input.c_str(), NULL);
		_int = static_cast<int>(_double);
		if (!(_double < 0 || _double > 127) && _input.length() == 1)
			_char = static_cast<char>(_double);
		printScalar();
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
			printScalar();
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
	printScalar();
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
	if (!(_int < 0 || _int > 127) && _input.length() == 1)
		_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
}

void	ScalarConverter::_convertFloat()
{
	double temp = std::strtod(_input.c_str(), NULL);
	if (temp > std::numeric_limits<double>::min() && temp < std::numeric_limits<double>::max())
		_int = static_cast<int>(temp);
	_float = std::strtof(_input.c_str(), NULL);
	if (!(_float < 0 || _float > 127) && _input.length() == 2)
		_char = static_cast<char>(_float);
	_double = temp;
}

void	ScalarConverter::_convertDouble()
{
	if (_input == "nan" || _input == "+inf" || _input == "+inff" || _input == "-inf" || _input == "-inff" || _input == "nanf")
	{
		_double = std::strtod(_input.c_str(), NULL);
		_float = std::strtof(_input.c_str(), NULL);
		return ;
	}
	_double = std::strtod(_input.c_str(), NULL);
	if (_double > std::numeric_limits<int>::min() && _double < std::numeric_limits<int>::max())
		_int = static_cast<int>(_double);
	if (!(_double < 0 || _double > 127) && _input.length() == 1)
		_char = static_cast<char>(_double);
	_float = static_cast<float>(_double);
}

void	ScalarConverter::printScalar()
{
	if (_char != 0)
		std::cout << "char: " << _char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (((_input != "0" && _input != "0.0" && _input != "0.0f") && _int == 0) || (_input == "nan" || _input == "nanf" || _input == "+inf" || _input == "+inff" || _input == "-inf" || _input == "-inff"))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << _int << std::endl;
	std::cout << "float: " << _float << "f" << std::endl;
	std::cout << "double: " << _double << std::endl;
}

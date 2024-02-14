#pragma once

# include <iostream>
# include <string>
# include <stdexcept>
# include <cstdlib>
# include <cctype>
# include <limits>

class ScalarConverter
{
	private:
		std::string		_input;
		char			_char;
		int				_int;
		float			_float;
		double			_double;

		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);

		void	_convertChar();
		void	_convertInt();
		void	_convertFloat();
		void	_convertDouble();

	public:
		ScalarConverter(const std::string& input);
		~ScalarConverter();

		void	convert();
};

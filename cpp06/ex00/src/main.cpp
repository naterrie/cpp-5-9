#include "ScalarConverter.hpp"

int main(int argv, char** argc)
{
	if (argv != 2)
	{
		std::cerr << "Usage: ./convert [value]" << std::endl;
		return 1;
	}
	ScalarConverter	converter(argc[1]);

	converter.convert();
	return 0;
}

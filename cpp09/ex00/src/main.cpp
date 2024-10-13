#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}

	BitcoinExchange btcExchange("data.csv");
	if (!btcExchange.loadDatabase())
	{
		return 1;
	}

	btcExchange.processInputFile(argv[1]);

	return 0;
}

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange(const std::string& databaseFilename);
		~BitcoinExchange();

		bool	loadDatabase();
		void	processInputFile(const std::string& inputFilename);

	private:
		std::string	_databaseFilename;
		std::map<std::string, float>	_db;

		bool		_isValidDate(const std::string& date);
		std::string	_findClosestDate(const std::string& date);
};

#endif

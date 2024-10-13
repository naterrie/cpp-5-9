#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(const std::string& databaseFilename) : _databaseFilename(databaseFilename)
{}

BitcoinExchange::~BitcoinExchange()
{}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2000 || year > 2100)
		return false;
	return true;
}

bool BitcoinExchange::loadDatabase()
{
	std::ifstream file(_databaseFilename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return false;
	}

	std::string line, date;
	float price;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		if (std::getline(ss, date, ',') && ss >> price)
		{
			_db[date] = price;
		}
	}
	file.close();
	return true;
}

std::string BitcoinExchange::findClosestDate(const std::string& date)
{
	std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
	if (it == _db.end() || it->first != date)
	{
		if (it != _db.begin())
			--it;
	}
	return it->first;
}

void BitcoinExchange::processInputFile(const std::string& inputFilename)
{
	std::ifstream file(inputFilename.c_str());
	std::string line;
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		std::string date, sep, valueStr;
		float value;

		if (!(ss >> date >> sep >> valueStr) || sep != "|")
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::stringstream valStream(valueStr);
		if (!(valStream >> value) || value < 0 || value > 1000) {
			if (value < 0)
				std::cerr << "Error: not a positive number." << std::endl;
			else
				std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		std::string closestDate = findClosestDate(date);
		float rate = _db[closestDate];
		float result = rate * value;

		std::cout << date << " => " << value << " = " << result << std::endl;
	}

	file.close();
}

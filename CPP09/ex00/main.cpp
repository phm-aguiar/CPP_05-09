#include "BitcoinExchange.hpp"

bool	startExchange(BitcoinExchange *exchange)
{
	float	value;

	std::ifstream inputFile("data.csv");
	std::string values;
	std::string key;
	if (inputFile.is_open())
	{
		std::getline(inputFile, key);
		while (std::getline(inputFile, key, ','))
		{
			if (key.empty())
				continue;
			std::getline(inputFile, values);
			value = std::strtof(values.c_str(), NULL);
			exchange->putExchange(key, value);
		}
		inputFile.close();
		return (true);
	}
	else
	{
		std::cerr << "Error: could not open file." << std::endl;
	}
	return (false);
	// exchange->printExchange();
}

void	dateOutRange(int *year, int *month, int *day)
{
	if (2022 < *year || (2022 == *year && *month > 3) || (2022 == *year
			&& *month == 3 && *day > 29))
	{
		*year = 2022;
		*month = 3;
		*day = 29;
	}
	if (*year < 2009 || (*year == 2009 && *month < 1) || (*year == 2009
			&& *month == 1 && *day < 3))
	{
		*year = 2009;
		*month = 1;
		*day = 3;
	}
}



bool	validateDate(std::string date)
{
	struct tm	timeStruct = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int			year;
	int			month;
	int			day;
	time_t		result;
	struct tm	*timeinfo;

	std::stringstream ss(date);
	ss >> year;
	ss.ignore(1);
	ss >> month;
	ss.ignore(1);
	ss >> day;
	timeStruct.tm_year = year - 1900;
	timeStruct.tm_mon = month - 1;
	timeStruct.tm_mday = day;
	result = mktime(&timeStruct);
	timeinfo = localtime(&result);
	if (timeinfo->tm_year != year - 1900 || timeinfo->tm_mon != month - 1 || timeinfo->tm_mday != day)
	{
		std::cerr <<RED "Error: bad input => " << date << RESET << std::endl;
		return (false);
	}
	dateOutRange(&year, &month, &day);
	return (true);
}

bool	quantityValidation(std::string quantity, BitcoinExchange *exchange, std::string key)
{
	float	value = exchange->getValue();
	std::stringstream ss(quantity);
	ss >> value;
	if (ss.fail())
	{
		std::cerr <<RED "Error: bad input => " << key << RESET << std::endl;
		return (false);
	}
	if (value < 0)
	{
		std::cerr <<RED "Error: not a positive number." << RESET << std::endl;
		return (false);
	}
	if (value > 1000)
	{
		std::cerr <<RED "Error: too large a number." << RESET << std::endl;
		return (false);
	}
	exchange->setValue(value);
	return (true);
}

bool	openInputFile(std::string filename, BitcoinExchange *exchange)
{
	std::ifstream inputFile;
	std::string key;
	std::string value;
	inputFile.open(filename.c_str());
	if (!inputFile.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (false);
	}
	std::getline(inputFile, key);
	while (std::getline(inputFile, key, '|'))
	{
		std::stringstream ss(key);
		ss >> key;
		std::getline(inputFile, value);
		if (!validateDate(key) || !quantityValidation(value, exchange, key))
			continue;
		exchange->searchExchange(key);
	}
	inputFile.close();
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid number of arguments." << std::endl;
		return (1);
	}
	BitcoinExchange	exchange =  BitcoinExchange();
	if (!startExchange(&exchange) || !openInputFile(argv[1], &exchange))
		return (1);
	return (0);
}

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::string dbName = "data.csv";
	std::ifstream dbFile(dbName.c_str());
	if (!dbFile.good()) {
		std::cerr << "Error: database doesn't exist." << std::endl;
		exit(1);
	}
	std::string line;
	while(dbFile.good()) {
		std::getline(dbFile, line);
		std::string date = line.substr(0, line.find(','));
		float val = atof(line.substr(line.find(',') + 1).c_str());
		_map[date] = val;
	}
	dbFile.close();
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
	*this = copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	(void)other;
	return (*this);
}

void BitcoinExchange::exchange(std::string date, float amount) {
	if (amount < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return ;
	}

	float rate = getExchangeRate(date);
	std::cout << date << " => " << amount << " = " << amount * rate << std::endl;
}

float BitcoinExchange::getExchangeRate(std::string date) {
	std::map<std::string, float>::iterator iter = _map.lower_bound(date);
	if (iter == _map.end()) {
		std::cout << "Error: No data: " << date << std::endl;
		exit(1);
	}
	return (iter->second);
}


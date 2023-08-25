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
	std::map<std::string, float>::iterator iter = _map.upper_bound(date);
	if (iter == _map.end()) {
		std::cout << "Error: No data: " << date << std::endl;
		exit(1);
	}
	iter--; 
	return (iter->second);
}

bool BitcoinExchange::isValid(std::string& line, std::string& date, float& amount) {
	if (line.empty() || line.compare("date | value") == 0)
		return false;

	if (line.find(" | ") == std::string::npos) {
		std::cerr << "Error: bad input => " << line << std::endl;
		return false;
	}

	date = line.substr(0, line.find(" | "));
	if (date.length() != 10) {
		std::cerr << "Error: bad date format => " << date << std::endl;
		return false;
	}
	if (date[4] != '-' || date[7] != '-') {
		std::cerr << "Error: bad date format => " << date << std::endl;
		return false;
	}

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	if (year < "0000" || year > "9999") {
		std::cerr << "Error: bad date format => " << date << std::endl;
		return false;
	}
	if (month < "01" || month > "12") {
		std::cerr << "Error: bad date format => " << date << std::endl;
		return false;
	}
	if (day < "01" || day > "31") {
		std::cerr << "Error: bad date format => " << date << std::endl;
		return false;
	}

	std::string amountStr = line.substr(line.find(" | ") + 3);
	for (unsigned int i = 0; i < amountStr.length(); i++) {
		if (amountStr[i] != '.' && (amountStr[i] < '0' || amountStr[i] > '9')) {
			std::cerr << "Error: not a positive number." << std::endl;
			return false;
		}
	}

	amount = std::atof(amountStr.c_str());
	if (amount > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::convert(std::ifstream& inputFile) {
	std::string line;
	std::string date;
	float amount;

	while (inputFile.good()) {
		std::getline(inputFile, line);

		if (isValid(line, date, amount))
			exchange(date, amount);
	}
}

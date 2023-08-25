#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _map;

		bool isValid(std::string& line, std::string& date, float& amount);
		float getExchangeRate(std::string date);
		void exchange(std::string date, float amount);

		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);

    public:
		BitcoinExchange();
		~BitcoinExchange();

		void convert(std::ifstream& inputFile);
};

#endif

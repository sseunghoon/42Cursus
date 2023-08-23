#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <map>

class BitcoinExchange {
	private:
		std::map<std::string, float> _map;
		float getExchangeRate(std::string date);


		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);

    public:
    	BitcoinExchange();
		~BitcoinExchange();

		void exchange(std::string date, float amount);
		

};

#endif

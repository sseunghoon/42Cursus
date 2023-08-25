#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN {
	private:
		RPN();
		RPN(const RPN& copy);
		RPN& operator=(const RPN& other);
		
    public:
    	~RPN();

		static void calculate(std::string& input);
};

#endif

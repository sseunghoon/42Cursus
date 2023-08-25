#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN& copy) {
	(void)copy;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return (*this);
}

RPN::~RPN() {
}

void RPN::calculate(std::string& input) {
	std::stack<double> stack;
	std::stringstream ss(input);
	std::string token;
	double a;
	double b;
	double result;

	while (ss >> token) {
		if (token.length() == 1 && (token[0] == '+' || 
									token[0] == '-' ||
									token[0] == '*' || 
									token[0] == '/' )) {
			if (stack.size() < 2) {
				std::cout << "Error" << std::endl;
				return ;
			}
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			switch (token[0]) {
				case '+':
					result = b + a;
					break;
				case '-':
					result = b - a;
					break;
				case '*':
					result = b * a;
					break;
				case '/':
					if (a == 0) {
						std::cout << "Error: Division by zero" << std::endl;
						return ;
					}
					result = b / a;
					break;
				default:
					std::cout << "Error: Invalid operator" << std::endl;
					return ;
			}
			stack.push(result);
		} else {
			char* end_ptr;
			double num = std::strtod(token.c_str(), &end_ptr);
			if (!(end_ptr[0] == 0 || (end_ptr[0] == 'f' && end_ptr[1] == 0))) {
				std::cout << "Error" << std::endl;
				return ;
			}
			stack.push(num);
		}
	}
	if (stack.size() != 1) {
		std::cout << "Error" << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter Default constructor called" << std::endl;	
}

ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter Destructor called: " << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	std::cout << "ScalarConverter Copy constructor called: " << std::endl;
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cv) {
	std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	(void)cv;

	return (*this);
}

void ScalarConverter::convert(std::string str) {
	double	num;
	char*	end_ptr;

	num = strtod(str.c_str(), &end_ptr);
	
	if (!(end_ptr[0] == 0 || (end_ptr[0] == 'f' && end_ptr[1] == 0))) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	std::cout << "char: ";
	if (num < 0 || num > 127 || isnan(num))
		std::cout << "impossible" << std::endl;
	else if (num < 32 || num > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;

	
	std::cout << "int: ";
	int iValue = static_cast<int>(num);
	if (num < INT_MIN || num > INT_MAX || isnan(num))
		std::cout << "impossible" << std::endl;
	else
		std::cout << iValue << std::endl;

	float fValue = static_cast<float>(num);
	double dValue = static_cast<double>(num);

	if (fValue - iValue == 0) {
		std::cout << "float: " << fValue << ".0f" << std::endl;
		std::cout << "double: " << dValue << ".0" << std::endl;
	} else {
		std::cout << "float: " << fValue << "f" << std::endl;
		std::cout << "double: " << dValue << std::endl;
	}
}

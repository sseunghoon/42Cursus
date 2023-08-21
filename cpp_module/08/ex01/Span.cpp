#include "Span.hpp"

Span::Span() {
	std::cout << "Span Default constructor called" << std::endl;	
}

Span::Span(unsigned int n) {
	std::cout << "Span Parameter constructor called" << std::endl;
	this->n = n;
}

Span::Span(const Span& copy) {
	std::cout << "Span Copy constructor called: " << std::endl;
	*this = copy;
}

Span& Span::operator=(const Span& other) {
	std::cout << "Span Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->n = other.n;
		this->vec = other.vec;
	}

	return (*this);
}

Span::~Span() {
	std::cout << "Span Destructor called: " << std::endl;
}

void	Span::addNumber(int num) {
	if (this->vec.size() >= this->n)
		throw std::exception();
	this->vec.push_back(num);
}

int		Span::shortestSpan() {
	if (vec.size() <= 1)
		throw std::exception();

	std::sort(vec.begin(), vec.end());

	int min = vec[1] - vec[0];
	for (unsigned int i = 1; i < vec.size(); i++) {
		if (vec[i] - vec[i - 1] < min)
			min = vec[i] - vec[i - 1];
	}
	return (min);
}

int		Span::longestSpan() {
	if (vec.size() <= 1)
		throw std::exception();

	std::sort(vec.begin(), vec.end());

	return (vec[vec.size() - 1] - vec[0]);
}

void 	Span::fillVector(int n) {
	for (int i = 0; i < n; i++)
		this->vec.push_back(i);
}
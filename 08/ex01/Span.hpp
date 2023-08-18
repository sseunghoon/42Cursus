#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class Span {
    private:
		std::vector<int> vec;
		unsigned int n;

    	Span();

	public:
		Span(unsigned int n);
		Span(const Span& copy);
		Span& operator=(const Span& copy);
		~Span();

		void	addNumber(int num);
		int		shortestSpan();
		int		longestSpan();
		void 	fillVector(int n);

};

#endif

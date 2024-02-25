#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _vec;

	public:
		Span();
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void addNumber(int number);
		void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

#include "Span.hpp"

Span::Span() : _n(0), _vec(0)
{
}

Span::Span(unsigned int n) : _n(n), _vec(0)
{
}

Span::Span(Span const &other)
{
	*this = other;
}

Span &Span::operator=(Span const &other)
{
	this->_n = other._n;
	this->_vec = other._vec;
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int number)
{
	if (this->_vec.size() >= this->_n)
		throw std::runtime_error("Container is full");
	this->_vec.push_back(number);
}

int	Span::shortestSpan()
{
	if (this->_vec.size() <= 1)
		throw std::runtime_error("Not enough elements to find a span");

	std::vector<int> sortedVec = this->_vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	int shortestSpan = sortedVec[1] - sortedVec[0];

	for (std::vector<int>::size_type i = 1; i < sortedVec.size() - 1; i++)
	{
		if (sortedVec[i + 1] - sortedVec[i] < shortestSpan)
			shortestSpan = sortedVec[i + 1] - sortedVec[i];
	}
	return shortestSpan;
}

int	Span::longestSpan()
{
	if (this->_vec.size() <= 1)
		throw std::runtime_error("Not enough elements to find a span");

	std::vector<int> sortedVec = this->_vec;
	std::sort(sortedVec.begin(), sortedVec.end());
	
	return sortedVec[sortedVec.size() - 1] - sortedVec[0];
}


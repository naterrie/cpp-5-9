#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <typeinfo>

template <typename T>
class PmergeMe
{
	public:
		PmergeMe() {}
		~PmergeMe() {}

		void	sort(T &container);

		void	printContainer(const T &container, const std::string prefix);
		void	timeProcess(const std::string type);

	private:
		void	_fordJohnsonSort(T &container, int start, int end);
		void	_insertBinary(T &sortedChain, int value);
		clock_t	_start;
		clock_t	_end;
};

#endif

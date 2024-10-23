#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <sstream>

class PmergeMe
{
	public:
		PmergeMe(const std::vector<int>& seq);
		~PmergeMe();

		void fordJohnsonSortVector();
		void fordJohnsonSortDeque();

		void printSequenceVector(const std::string& message);
		void printSequenceDeque(const std::string& message);

		double getElapsedTime() const;

	private:
		std::vector<int> _vec;
		std::deque<int> _deq;
		clock_t _start_time;
		clock_t _end_time;

		void _dichotomicInsert(std::vector<int>& vec, int element);
		void _dichotomicInsert(std::deque<int>& deq, int element);
};

#endif

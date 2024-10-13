#pragma once

#include <algorithm>
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

		void fordJohnsonSortVector();
		void fordJohnsonSortDeque();

		void printSequenceVector(const std::string& message);
		void printSequenceDeque(const std::string& message);

		double getElapsedTime() const;

	private:
		std::vector<int> vec;
		std::deque<int> deq;
		clock_t start_time;
		clock_t end_time;

		void insertWithMinimalComparisons(std::vector<int>& vec, int element);
		void insertWithMinimalComparisons(std::deque<int>& deq, int element);
};

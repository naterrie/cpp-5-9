#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& seq): vec(seq.begin(), seq.end()), deq(seq.begin(), seq.end())
{}

void PmergeMe::fordJohnsonSortVector()
{
	start_time = clock();

	if (vec.size() < 2)
		return;

	std::vector<int> sorted_vec;
	for (size_t i = 0; i < vec.size(); i += 2)
	{
		if (i + 1 < vec.size()) {
			if (vec[i] > vec[i + 1])
				std::swap(vec[i], vec[i + 1]);

			sorted_vec.push_back(vec[i + 1]);
			insertWithMinimalComparisons(sorted_vec, vec[i]);
		}
		else
			insertWithMinimalComparisons(sorted_vec, vec[i]);
	}

	vec = sorted_vec;

	end_time = clock();
}

void PmergeMe::fordJohnsonSortDeque()
{
	start_time = clock();

	if (deq.size() < 2)
		return;

	std::deque<int> sorted_deq;
	for (size_t i = 0; i < deq.size(); i += 2)
	{
		if (i + 1 < deq.size())
		{
			if (deq[i] > deq[i + 1])
				std::swap(deq[i], deq[i + 1]);

			sorted_deq.push_back(deq[i + 1]);
			insertWithMinimalComparisons(sorted_deq, deq[i]);
		}
		else
			insertWithMinimalComparisons(sorted_deq, deq[i]);
	}
	deq = sorted_deq;
	end_time = clock();
}

void PmergeMe::printSequenceVector(const std::string& message)
{
	std::cout << message;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printSequenceDeque(const std::string& message)
{
	std::cout << message;

	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

double PmergeMe::getElapsedTime() const
{
	return static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;
}

void PmergeMe::insertWithMinimalComparisons(std::vector<int>& vec, int element)
{
	std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), element);
	vec.insert(it, element);
}


void PmergeMe::insertWithMinimalComparisons(std::deque<int>& deq, int element)
{
	std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), element);
	deq.insert(it, element);
}

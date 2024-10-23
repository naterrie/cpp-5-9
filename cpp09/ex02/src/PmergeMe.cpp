#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::vector<int>& seq): _vec(seq.begin(), seq.end()), _deq(seq.begin(), seq.end())
{}

PmergeMe::~PmergeMe()
{}

void PmergeMe::fordJohnsonSortVector()
{
	_start_time = clock();

	if (_vec.size() < 2)
		return;

	std::vector<int> sorted_vec;
	std::vector<int> remaining;

	for (size_t i = 0; i < _vec.size(); i += 2)
	{
		if (i + 1 < _vec.size())
		{
			if (_vec[i] > _vec[i + 1])
				std::swap(_vec[i], _vec[i + 1]);

			sorted_vec.push_back(_vec[i + 1]);
			remaining.push_back(_vec[i]);
		}
		else
			remaining.push_back(_vec[i]);
	}
	for (size_t i = 1; i < sorted_vec.size(); ++i)
	{
		int key = sorted_vec[i];
		int j = i - 1;

		while (j >= 0 && sorted_vec[j] > key)
		{
			sorted_vec[j + 1] = sorted_vec[j];
			j--;
		}
		sorted_vec[j + 1] = key;
	}

	for (size_t i = 0; i < remaining.size(); ++i)
		_dichotomicInsert(sorted_vec, remaining[i]);

	_vec = sorted_vec;

	_end_time = clock();
}

void PmergeMe::fordJohnsonSortDeque()
{
	_start_time = clock();

	if (_deq.size() < 2)
		return;

	std::deque<int> sorted_deq;
	std::deque<int> remaining;

	for (size_t i = 0; i < _deq.size(); i += 2)
	{
		if (i + 1 < _deq.size())
		{
			if (_deq[i] > _deq[i + 1])
				std::swap(_deq[i], _deq[i + 1]);

			sorted_deq.push_back(_deq[i + 1]);
			remaining.push_back(_deq[i]);
		}
		else
			remaining.push_back(_deq[i]);
	}

	for (size_t i = 1; i < sorted_deq.size(); ++i)
	{
		int key = sorted_deq[i];
		int j = i - 1;

		while (j >= 0 && sorted_deq[j] > key)
		{
			sorted_deq[j + 1] = sorted_deq[j];
			j--;
		}
		sorted_deq[j + 1] = key;
	}

	for (size_t i = 0; i < remaining.size(); ++i)
		_dichotomicInsert(sorted_deq, remaining[i]);

	_deq = sorted_deq;

	_end_time = clock();
}

void PmergeMe::printSequenceVector(const std::string& message)
{
	std::cout << message;
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void PmergeMe::printSequenceDeque(const std::string& message)
{
	std::cout << message;

	for (std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

double PmergeMe::getElapsedTime() const
{
	return static_cast<double>(_end_time - _start_time) / CLOCKS_PER_SEC;
}

void PmergeMe::_dichotomicInsert(std::vector<int>& vec, int element)
{
	std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), element);
	vec.insert(it, element);
}

void PmergeMe::_dichotomicInsert(std::deque<int>& deq, int element)
{
	std::deque<int>::iterator it = std::lower_bound(deq.begin(), deq.end(), element);
	deq.insert(it, element);
}

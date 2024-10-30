#include "PmergeMe.hpp"

template <typename T>
void PmergeMe<T>::sort(T &container)
{
	if (container.size() <= 1)
		return;

	this->_start = clock();
	_fordJohnsonSort(container, 0, container.size() - 1);
	this->_end = clock();
}

template <typename T>
void PmergeMe<T>::_fordJohnsonSort(T &container, int start, int end)
{
	if (end - start <= 0)
		return;

	T winners, losers;
	for (int i = start; i < end; i += 2)
	{
		if (container[i] > container[i + 1])
		{
			winners.push_back(container[i]);
			losers.push_back(container[i + 1]);
		}
		else
		{
			winners.push_back(container[i + 1]);
			losers.push_back(container[i]);
		}
	}

	bool hasOddElement = (end - start + 1) % 2 != 0;
	int oddElement;
	if (hasOddElement)
		oddElement = container[end];

	_fordJohnsonSort(winners, 0, winners.size() - 1);

	for (typename T::iterator it = losers.begin(); it != losers.end(); ++it)
		_insertBinary(winners, *it);

	if (hasOddElement)
		_insertBinary(winners, oddElement);

	for (typename T::size_type i = 0; i < winners.size(); ++i)
		container[start + i] = winners[i];
}

template <typename T>
void PmergeMe<T>::_insertBinary(T &sortedChain, int value)
{
	int left = 0;
	int right = sortedChain.size() - 1;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (sortedChain[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	sortedChain.insert(sortedChain.begin() + left, value);
}

template <typename T>
void PmergeMe<T>::printContainer(const T &container, std::string prefix)
{
	std::cout << prefix;
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::timeProcess(std::string type)
{
	double timeTaken = static_cast<double>(this->_end - this->_start);
	std::cout << "Time to process with std::" << type << ": " << timeTaken << " us" << std::endl;
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

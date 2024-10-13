#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: You must provide a sequence of positive integers." << std::endl;
		return 1;
	}

	std::vector<int> sequence;

	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		long long number;
		iss >> number;

		if (iss.fail() || !iss.eof())
		{
			std::cerr << "Error: \"" << argv[i] << "\" is not a valid integer." << std::endl;
			return 1;
		}

		if (number < 0)
		{
			std::cerr << "Error: Negative numbers are not allowed." << std::endl;
			return 1;
		}

		if (number > std::numeric_limits<int>::max())
		{
			std::cerr << "Error: The number \"" << number << "\" exceeds the maximum allowed integer value." << std::endl;
			return 1;
		}

		sequence.push_back(static_cast<int>(number));
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < sequence.size(); ++i)
		std::cout << sequence[i] << " ";

	std::cout << std::endl;

	PmergeMe pmerge(sequence);

	pmerge.fordJohnsonSortVector();
	pmerge.printSequenceVector("After: ");
	std::cout << "Time to process a range of " << sequence.size() << " elements with std::vector: " << pmerge.getElapsedTime() << " us" << std::endl;

	pmerge.fordJohnsonSortDeque();
	pmerge.printSequenceDeque("After: ");
	std::cout << "Time to process a range of " << sequence.size() << " elements with std::deque: " << pmerge.getElapsedTime() << " us" << std::endl;

	return 0;
}

#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <positive numbers>" << std::endl;
		return 1;
	}

	std::vector<int> vecInput;
	std::deque<int> deqInput;

	for (int i = 1; i < argc; ++i)
	{
		int num;
		std::istringstream iss(argv[i]);
		if (!(iss >> num) || num <= 0)
		{
			std::cerr << "All arguments must be positive numbers." << std::endl;
			return 1;
		}
		vecInput.push_back(num);
		deqInput.push_back(num);
	}

	PmergeMe<std::vector<int> > vecSorter;

	vecSorter.printContainer(vecInput, "Before: ");
	vecSorter.sort(vecInput);
	vecSorter.printContainer(vecInput, "After: ");
	vecSorter.timeProcess("vector");

	/* Using the same sort, so i dont print */
	PmergeMe<std::deque<int> > deqSorter;
	deqSorter.sort(deqInput);
	deqSorter.timeProcess("deque");

	return 0;
}

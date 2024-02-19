#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(int);

	std::cout << "Testing with integer array: ";
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t doubleArrayLength = sizeof(doubleArray) / sizeof(double);

	std::cout << "Testing with double array: ";
	iter(doubleArray, doubleArrayLength, printElement<double>);
	std::cout << std::endl;

	std::string stringArray[] = {"Hello", "World", "C++", "Templates"};
	size_t stringArrayLength = sizeof(stringArray) / sizeof(std::string);

	std::cout << "Testing with string array: ";
	iter(stringArray, stringArrayLength, printElement<std::string>);
	std::cout << std::endl;
}

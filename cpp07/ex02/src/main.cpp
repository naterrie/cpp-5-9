#include "Array.hpp"

int main()
{
	Array<int> intArray(5);

	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		intArray[i] = i * 2;
	}

	for (unsigned int i = 0; i < intArray.size(); ++i)
	{
		std::cout << "Element at index " << i << ": " << intArray[i] << std::endl;
	}

	try
	{
		intArray[10] = 42;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

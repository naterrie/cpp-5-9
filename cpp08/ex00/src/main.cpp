#include "easyfind.hpp"

int main()
{
	{
		try
		{
			std::vector<int> vec;
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);
			vec.push_back(5);
			int valueToFind = 3;

			std::vector<int>::iterator result = easyfind(vec, valueToFind);

			std::cout << "La valeur " << valueToFind << " a été trouvée à la position : " << std::distance(vec.begin(), result) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		try
		{
			std::vector<int> vec;
			vec.push_back(1);
			vec.push_back(2);
			vec.push_back(3);
			vec.push_back(4);
			vec.push_back(5);
			int valueToFind = 6;

			std::vector<int>::iterator result = easyfind(vec, valueToFind);

			std::cout << "La valeur " << valueToFind << " a été trouvée à la position : " << std::distance(vec.begin(), result) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}

#include "Serialization.hpp"

int main()
{
	uintptr_t	raw;
	Data*		ptr = new Data;

	ptr->str = "hihihiha";

	std::cout << "ptr->str: " << ptr->str << std::endl;
	raw = Serializer::serialize(ptr);
	std::cout << "raw: " << raw << std::endl;

	ptr = NULL;
	ptr = Serializer::deserialize(raw);
	std::cout << "ptr->str: " << ptr->str << std::endl;

	delete ptr;
}

#pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <cctype>
# include <stdexcept>

typedef unsigned long uintptr_t;

typedef struct Data
{
	std::string	str;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer&	operator=(const Serializer& other);
		~Serializer();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

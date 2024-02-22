#pragma once

# include <iostream>
# include <stdexcept>

template <typename T>
class Array
{
	public:
		Array(void): _size(0)
		{
			_array = new T[0];
		}

		Array(unsigned int n): _size(n)
		{
			_array = new T[n];
		}

		Array(const Array &other): _size(other._size)
		{
			_array = new T[other._size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}

		Array &operator=(const Array &other)
		{
			if (this == &other)
				return *this;
			delete[] _array;
			_size = other._size;
			_array = new T[other._size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
			return *this;
		}

		~Array(void)
		{
			delete[] _array;
		}

		T &operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return _array[i];
		}

		unsigned int size(void) const
		{
			return _size;
		}

	private:
		T* _array;
		unsigned int _size;
};

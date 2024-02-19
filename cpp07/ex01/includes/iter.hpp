#pragma once

#include <iostream>

template <typename T, typename F>
void	iter (T *array, size_t length, void (*f)(F const &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T, typename Func>
void	iter (T *array, size_t length, void (*f)(Func &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

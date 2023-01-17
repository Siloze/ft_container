#ifndef SWAP_HPP
#define SWAP_HPP

namespace ft
{
    template <class T>
    void swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}
}
#endif
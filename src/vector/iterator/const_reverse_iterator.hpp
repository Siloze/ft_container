#ifndef CONST_REVERSE_ITERATOR_HPP
#define CONST_REVERSE_ITERATOR_HPP
#include "reverse_iterator.hpp"
namespace ft
{
	template <typename T>
	class const_reverse_iterator
	{
		public :
			const_reverse_iterator() : _ptr(NULL) { return ; };
			const_reverse_iterator(T* ptr) : _ptr(ptr) { return ; };
			const_reverse_iterator(const const_reverse_iterator& rhs) { *this = rhs; return ; };
            const_reverse_iterator(const iterator<T>& rhs) { _ptr = rhs.operator->(); return ; };
			~const_reverse_iterator() { return ; };

			const_reverse_iterator& operator=(const const_reverse_iterator& rhs)
			{
				this->_ptr = rhs._ptr;
				return *this;
			};

			const T& operator*() const { return *this->_ptr; };
			const T* operator->() const { return this->_ptr; };
			const_reverse_iterator& operator++() { this->_ptr--; return *this; };
			const_reverse_iterator operator++(int) { const_reverse_iterator tmp(*this); this->_ptr--; return tmp; };
			const_reverse_iterator& operator--() { this->_ptr++; return *this; };
			const_reverse_iterator operator--(int) { const_reverse_iterator tmp(*this); this->_ptr++; return tmp; };
			const_reverse_iterator operator+(int n) const { return const_reverse_iterator(this->_ptr - n); };
			const_reverse_iterator operator-(int n) const { return const_reverse_iterator(this->_ptr + n); };
            friend const_reverse_iterator operator+(int n, const const_reverse_iterator &it) { return const_reverse_iterator(it._ptr - n); };
            friend const_reverse_iterator operator-(int n, const const_reverse_iterator &it) { return const_reverse_iterator(it._ptr + n); };

			const_reverse_iterator& operator+=(int n) { this->_ptr -= n; return *this; };
			const_reverse_iterator& operator-=(int n) { this->_ptr += n; return *this; };
			long operator+(const const_reverse_iterator &n) const { return this->_ptr + n._ptr; };
            long operator-(const const_reverse_iterator &n) const { return this->_ptr - n._ptr; };

            const_reverse_iterator& operator+=(const const_reverse_iterator &n) { this->_ptr += n._ptr; return *this; };
            const_reverse_iterator& operator-=(const const_reverse_iterator &n) { this->_ptr -= n._ptr; return *this; };
			bool operator==(const const_reverse_iterator& rhs) const { return this->_ptr == rhs._ptr; };
			bool operator!=(const const_reverse_iterator& rhs) const { return this->_ptr != rhs._ptr; };
			bool operator<(const const_reverse_iterator& rhs) const { return this->_ptr > rhs._ptr; };
			bool operator>(const const_reverse_iterator& rhs) const { return this->_ptr < rhs._ptr; };
			bool operator<=(const const_reverse_iterator& rhs) const { return this->_ptr >= rhs._ptr; };
			bool operator>=(const const_reverse_iterator& rhs) const { return this->_ptr <= rhs._ptr; };
			const T& operator[](int n) const { return this->_ptr[-n]; };

		private :
			T* _ptr;
	};
}


#endif
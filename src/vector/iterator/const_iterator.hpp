#ifndef CONST_ITERATOR_HPP
#define CONST_ITERATOR_HPP
#include "iterator.hpp"
namespace ft
{
    template <typename T>
    class const_iterator : public iterator<T>
    {
        public :
            const_iterator() : _ptr(NULL) { return ; };
            const_iterator(T* ptr) : _ptr(ptr) { return ; };
            const_iterator(const const_iterator& rhs) { *this = rhs; return ; };
            const_iterator(const iterator<T>& rhs) { _ptr = rhs.operator->(); return ; };
            ~const_iterator() { return ; };

            const_iterator& operator=(const const_iterator& rhs)
            { this->_ptr = rhs._ptr;
                return *this;
            };

            const T& operator*() const { return *this->_ptr; };
            const T* operator->() const { return this->_ptr; };
            const_iterator& operator++() { this->_ptr++; return *this; };
            const_iterator operator++(int) { const_iterator tmp(*this); this->_ptr++; return tmp; };
            const_iterator& operator--() { this->_ptr--; return *this; };
            const_iterator operator--(int) { const_iterator tmp(*this); this->_ptr--; return tmp; };
    
            const_iterator operator+(int n) const { return const_iterator(this->_ptr + n); };
            const_iterator operator-(int n) const { return const_iterator(this->_ptr - n); };
            friend const_iterator operator+(int n, const const_iterator &it) { return const_iterator(it._ptr + n); };
            friend const_iterator operator-(int n, const const_iterator &it) { return const_iterator(it._ptr - n); };
            const_iterator& operator+=(int n) { this->_ptr += n; return *this; };
            const_iterator& operator-=(int n) { this->_ptr -= n; return *this; };
            long operator+(const const_iterator &n) const { return this->_ptr + n._ptr; };
            long operator-(const const_iterator &n) const { return this->_ptr - n._ptr; };

            const_iterator& operator+=(const const_iterator &n) { this->_ptr += n._ptr; return *this; };
            const_iterator& operator-=(const const_iterator &n) { this->_ptr -= n._ptr; return *this; };
            bool operator==(const const_iterator& rhs) const { return this->_ptr == rhs._ptr; };
            bool operator!=(const const_iterator& rhs) const { return this->_ptr != rhs._ptr; };
            bool operator<(const const_iterator& rhs) const { return this->_ptr < rhs._ptr; };
            bool operator>(const const_iterator& rhs) const { return this->_ptr > rhs._ptr; };
            bool operator<=(const const_iterator& rhs) const { return this->_ptr <= rhs._ptr; };
            bool operator>=(const const_iterator& rhs) const { return this->_ptr >= rhs._ptr; };
            const T& operator[](int n) const { return this->_ptr[n]; };

        private :
            T* _ptr;
    };
}


#endif
#ifndef iterator_HPP
# define iterator_HPP

# include <iostream>
namespace ft
{
    template <typename T>
    class iterator
    {
        public :
            iterator() : _ptr(NULL) { return ; };
            iterator(T* ptr) : _ptr(ptr) { return ; };
            iterator(const iterator& rhs) { this->_ptr = rhs.operator->(); return ; };
            ~iterator() { return ; };

            iterator& operator=(const iterator& rhs)
            {
                this->_ptr = rhs._ptr;
                return *this;
            };

            T& operator*() const { return *this->_ptr; };
            T* operator->() const { return this->_ptr; };

            iterator& operator++() { this->_ptr++; return *this; };
            iterator operator++(int) { iterator tmp(*this); this->_ptr++; return tmp; };
            iterator& operator--() { this->_ptr--; return *this; };
            iterator operator--(int) { iterator tmp(*this); this->_ptr--; return tmp; };

            iterator operator+(int n) const { return iterator(this->_ptr + n); };
            iterator operator-(int n) const { return iterator(this->_ptr - n); };
            friend iterator operator+(int n, const iterator &it) { return iterator(it._ptr + n); };
            friend iterator operator-(int n, const iterator &it) { return iterator(it._ptr - n); };

            iterator& operator+=(int n) { this->_ptr += n; return *this; };
            iterator& operator-=(int n) { this->_ptr -= n; return *this; };

            long operator+(const iterator &n) const { return this->_ptr + n._ptr; };
            long operator-(const iterator &n) const { return this->_ptr - n._ptr; };

            iterator& operator+=(const iterator &n) { this->_ptr += n._ptr; return *this; };
            iterator& operator-=(const iterator &n) { this->_ptr -= n._ptr; return *this; };
            
            // template <class InputIterator>
            // bool operator==(const InputIterator& rhs) const { return this->_ptr == rhs._ptr; };
            // template <class InputIterator>
            // bool operator!=(const InputIterator& rhs) const { return this->_ptr != rhs._ptr; };
            // template <class InputIterator>
            // bool operator<(const InputIterator& rhs) const { return this->_ptr < rhs._ptr; };
            // template <class InputIterator>
            // bool operator>(const InputIterator& rhs) const { return this->_ptr > rhs._ptr; };
            // template <class InputIterator>
            // bool operator<=(const InputIterator& rhs) const { return this->_ptr <= rhs._ptr; };
            // template <class InputIterator>
            // bool operator>=(const InputIterator& rhs) const { return this->_ptr <= rhs._ptr; };
            bool operator!=(const iterator& rhs) const { return this->_ptr != rhs._ptr; };
            bool operator<(const iterator& rhs) const { return this->_ptr < rhs._ptr; };
            bool operator>(const iterator& rhs) const { return this->_ptr > rhs._ptr; };
            bool operator<=(const iterator& rhs) const { return this->_ptr <= rhs._ptr; };
            bool operator>=(const iterator& rhs) const { return this->_ptr >= rhs._ptr; };
            T& operator[](int n) const { return this->_ptr[n]; };

        private :
            T* _ptr;
    };

}

# endif
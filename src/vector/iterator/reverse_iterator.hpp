#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{
    template <typename T>
    class reverse_iterator
    {
        public :
            reverse_iterator() : _ptr(NULL) { return ; };
            reverse_iterator(T* ptr) : _ptr(ptr) { return ; };
            reverse_iterator(const reverse_iterator& rhs) { *this = rhs; return ; };
            reverse_iterator(const iterator<T>& rhs) { _ptr = rhs.operator->(); return ; };
            ~reverse_iterator() { return ; };

            reverse_iterator& operator=(const reverse_iterator& rhs)
            {
                this->_ptr = rhs._ptr;
                return *this;
            };

            T& operator*() const { return *this->_ptr; };
            T* operator->() const { return this->_ptr; };
            reverse_iterator& operator++() { this->_ptr--; return *this; };
            reverse_iterator operator++(int) { reverse_iterator tmp(*this); this->_ptr--; return tmp; };
            reverse_iterator& operator--() { this->_ptr++; return *this; };
            reverse_iterator operator--(int) { reverse_iterator tmp(*this); this->_ptr++; return tmp; };
            reverse_iterator operator+(int n) const { return reverse_iterator(this->_ptr - n); };
            reverse_iterator operator-(int n) const { return reverse_iterator(this->_ptr + n); };
            reverse_iterator& operator+=(int n) { this->_ptr -= n; return *this; };
            reverse_iterator& operator-=(int n) { this->_ptr += n; return *this; };
            long operator+(const reverse_iterator &n) const { return this->_ptr + n._ptr; };
            long operator-(const reverse_iterator &n) const { return this->_ptr - n._ptr; };

            reverse_iterator& operator+=(const reverse_iterator &n) { this->_ptr += n._ptr; return *this; };
            reverse_iterator& operator-=(const reverse_iterator &n) { this->_ptr -= n._ptr; return *this; };
            bool operator==(const reverse_iterator& rhs) const { return this->_ptr == rhs._ptr; };
            bool operator!=(const reverse_iterator& rhs) const { return this->_ptr != rhs._ptr; };
            bool operator<(const reverse_iterator& rhs) const { return this->_ptr > rhs._ptr; };
            bool operator>(const reverse_iterator& rhs) const { return this->_ptr < rhs._ptr; };
            bool operator<=(const reverse_iterator& rhs) const { return this->_ptr >= rhs._ptr; };
            bool operator>=(const reverse_iterator& rhs) const { return this->_ptr <= rhs._ptr; };
            T& operator[](int n) const { return this->_ptr[-n]; };

        private :
            T* _ptr;
    };
}
# endif
#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../../includes/includes.hpp"
namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef Allocator allocator_type;
		typedef T value_type;
		typedef size_t size_type;
		typedef ptrdiff_t difference_type;
		typedef typename Allocator::reference reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef typename ft::iterator<T> iterator;
		typedef typename ft::const_iterator<T> const_iterator;
		typedef typename ft::reverse_iterator<T> reverse_iterator;
		typedef typename ft::const_reverse_iterator<T> const_reverse_iterator;

	public:
		// ---------------CONSTRUCTORS------------------
		explicit vector(const allocator_type &alloc = allocator_type()) : _data(NULL), _size(0), _capacity(0), _allocator(alloc)
		{
			return;
		};

		vector(size_t n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(n), _capacity(n), _allocator(alloc)
		{
			this->_data = this->_allocator.allocate(n);
			for (size_t i = 0; i < n; i++)
				this->_data[i] = val;
		};

		vector(const vector &x)
		{ // A REFAIRE
			this->_size = x._size;
			this->_capacity = x._capacity;
			this->_data = this->_allocator.allocate(this->_capacity);
			for (size_t i = 0; i < this->_size; i++)
				this->_data[i] = x._data[i];
			this->_allocator = x._allocator;
		};

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()) : _allocator(alloc)
		{
			this->_size = 0;
			this->_capacity = 0;
			this->_data = NULL;
			while (first != last)
			{
				this->push_back(*first);
				first++;
			}
		};
		// ---------------DESTRUCTOR------------------
		~vector()
		{
			// this->_allocator.deallocate(this->_data, this->_capacity);
			return;
		};

		// ---------------OPERATOR=------------------
		vector &operator=(const vector &rhs)
		{
			this->_allocator.deallocate(_data, _capacity);
			_size = rhs._size;
			_capacity = rhs._capacity;
			_data = this->_allocator.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
				_data[i] = rhs._data[i];
			return *this;
		};

		// ---------------ITERATOR------------------
		ft::iterator<T> begin() const
		{
			return iterator(&this->_data[0]);
		};

		ft::iterator<T> end() const
		{
			return iterator(&this->_data[this->_size]);
		};

		ft::reverse_iterator<T> rbegin() const
		{
			return reverse_iterator(&this->_data[this->_size - 1]);
		};

		ft::reverse_iterator<T> rend() const
		{
			return reverse_iterator(&this->_data[-1]);
		};

		ft::const_iterator<T> cbegin() const
		{
			return const_iterator(&this->_data[0]);
		};

		ft::const_iterator<T> cend() const
		{
			return const_iterator(&this->_data[this->_size]);
		};
		ft::const_reverse_iterator<T> crbegin() const
		{
			return const_reverse_iterator(&this->_data[this->_size - 1]);
		};
		ft::const_reverse_iterator<T> crend() const
		{
			return const_reverse_iterator(&this->_data[-1]);
		};
		//----------------ALL GETTER---------------------------

		std::allocator<T> get_allocator() const { return this->_allocator; };

		//--------------CAPACITY--------------------------------
		size_t size() const
		{
			return this->_size;
		};
		size_t max_size() const
		{
			return this->_allocator.max_size();
		};
		size_t capacity() const { return this->_capacity; };

		void resize(size_t n, T val = T())
		{
			if (n > this->_size)
			{
				if (this->_capacity == 0)
					this->_capacity++;
				while (n > this->_capacity)
				{
					this->_capacity *= 2;
					if (this->_capacity + 1 == n)
						this->_capacity++;
				}
				this->_data = this->_allocator.allocate(this->_capacity);
				for (size_t i = this->_size; i < n; i++)
					this->_data[i] = val;
			}
			this->_size = n;
		};

		void reserve(size_t n)
		{
			if (n > this->_capacity)
			{
				T *tmp = this->_allocator.allocate(n);
				for (size_t i = 0; i < this->_size; i++)
					tmp[i] = this->_data[i];
				this->_allocator.deallocate(this->_data, this->_capacity);
				this->_data = tmp;
				this->_capacity = n;
			}
		};

		bool empty() const
		{
			if (this->_size == 0)
				return true;
			return false;
		};

		void shrink_to_fit(void)
		{
			if (this->_size < this->capacity())
			{
				T *tmp = this->_allocator.allocate(this->_size);
				for (size_t i = 0; i < this->_size; i++)
					tmp[i] = this->_data[i];
				this->_allocator.deallocate(this->_data, this->_capacity);
				this->_data = tmp;
				this->_capacity = this->_size;
			}
		}

		//--------------ELEMENT ACCESS---------------------------
		T &operator[](size_t n)
		{
			return this->_data[n];
		};

		T &at(size_t n) const
		{
			if (n >= this->_size)
				throw std::out_of_range("Out of range");
			return this->_data[n];
		};

		T &front(void) const
		{
			if (this->_size == 0)
				throw std::out_of_range("Out of range");
			return this->_data[0];
		}

		T &back(void) const
		{
			if (this->_size == 0)
				throw std::out_of_range("Out of range");
			return this->_data[this->_size - 1];
		}

		T *data()
		{
			return this->_data;
		};

		//--------------MODIFIERS--------------------------------

		void clear()
		{
			if (this->size())
			{
				for (iterator it = this->begin(); it != this->end(); it++)
					this->_allocator.destroy(&(*it));
			}
			this->_size = 0;
		};

		void assign(size_type n, const value_type &val)
		{
			this->clear();
			for (size_t i = 0; i < n; i++)
				this->push_back(val);
		};

		template <class InputIterator>
		void assign(typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) // InputIterator first, InputIterator last)
		{
			this->clear();
			while (first != last)
			{
				this->push_back(*first);
				first++;
			}
		};

		void push_back(const T &val)
		{
			if (this->_size == 0)
				this->reserve(1);
			else if (this->_size == this->_capacity)
				this->reserve(this->_capacity * 2);
			this->_data[this->_size] = val;
			this->_size++;
		};

		void pop_back(void)
		{
			if (this->_size)
			{
				this->_allocator.destroy(&this->_data[this->_size - 1]);
				this->_size--;
			}
		};

		iterator insert(iterator position, const T &val)
		{
			if (this->_size == this->_capacity)
				this->reserve(this->_capacity * 2);
			iterator it = this->end();
			while (it != position)
			{
				*it = *(it - 1);
				it--;
			}
			*it = val;
			this->_size++;
			return position;
		};

		void insert(iterator position, size_type n, const value_type &val)
		{
			while (this->_size + n > this->_capacity)
				this->reserve(this->_capacity * 2);
			this->_size += n;
			iterator it = this->end();
			while (it != position)
			{
				*it = *(it - n);
				it--;
			}
			for (size_t i = 0; i < n; i++)
				*(it + i) = val;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) //typename ft::enable_if<!ft::is_integral<InputIterator>::type, InputIterator>::value first
		{
			size_t len = 0;
			size_t pos = position - this->begin();
			for (InputIterator it = first; it != last; it++)
			{
				std::cout << "oeoe" << std::endl;
				len++;
			}
			if (this->_size == 0)
				this->reserve(1);
			while (this->_size + len > this->_capacity)
			{
				this->reserve(this->_capacity * 2);
				std::cout << "oeoe2 size :" << this->_size  << " len : " << len << "capacity" << this->_capacity << std::endl;
			}
			this->_size += len;
			position = this->begin() + pos;
			iterator it = position + len;
			for (size_t i = 0; i < len; i++)
				*(it + i) = *(it + i - len);
			for (InputIterator it = first; it != last; it++)
				*position++ = *it;
		}

		iterator erase(iterator position)
		{
			iterator it = position;
			this->_allocator.destroy(it.operator->());
			while (it != this->end() - 1)
			{
				*it = *(it + 1);
				it++;
			}
			this->_size--;
			return position;
		};

		iterator erase(iterator first, iterator last)
		{
			for (size_t len = last - first; len > 0; len--)
				this->erase(first);
			return (first);
		}

	private:
		T *_data;
		size_t _size;
		size_t _capacity;
		Allocator _allocator;
	};
}

#endif
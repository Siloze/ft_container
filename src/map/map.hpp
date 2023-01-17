#ifndef MAP_HPP
#define MAP_HPP

#include "../../includes/includes.hpp"
namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > > 
	class map
	{
		public :
			typedef				Key						key_type;
			typedef				T						mapped_type;
			typedef typename	ft::pair<const Key, T>	value_type;
			typedef typename	Compare					key_compare;
			typedef typename	Alloc					allocator_type;
			typedef typename	Alloc::reference		reference;
			typedef typename	Alloc::const_reference	const_reference;
			typedef typename	Alloc::pointer			pointer;
			typedef typename	Alloc::const_pointer	const_pointer;
			typedef typename	Alloc::difference_type	difference_type;
			typedef typename	Alloc::size_type		size_type;

			//-------------------------CONSTRUCTORS & DESTRUCTOR-------------------------//
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _map(NULL), _size(0), _capacity(0), _comp(comp), _alloc(alloc) 
				{return ;};
			template <class InputIterator>
			map(ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			{return ;};
			map(const map& x) : map(NULL), size(0), capacity(0), comp(x.comp), alloc(x.alloc)
				{
					this->_map = _alloc.allocate(x._capacity);
					for (size_t i = 0; i < x._size; i++)
						this->_map[i] = x._map[i];
					this->_size = x._size;
					this->_capacity = x._capacity;
				};
			~map()
				{
					if (this->_map)
						this->_alloc.deallocate(this->_map, this->_capacity);
				};
			//--------------------------ITERATORS--------------------------//

			//--------------------------CAPACITY--------------------------//
			bool empty() const
				{return (this->_size == 0);};
			size_type size() const
				{return (this->_size);};
			size_type max_size() const
				{return (this->_alloc.max_size());};
			//--------------------------ELEMENT ACCESS--------------------------//

			//--------------------------MODIFIERS--------------------------//

			//--------------------------OBERSERVERS--------------------------//
			key_compare key_comp() const
				{return (this->_comp);};
			// value_compare value_comp() const
			// 	{return (this->_comp);};


			private :
				ft::pair<const Key,T>	*_map;
				size_type				_size;
				size_type				_capacity;
				key_compare				_comp;
				allocator_type			_alloc;
	};
}

#endif
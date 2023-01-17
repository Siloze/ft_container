#ifndef PAIR_HPP
#define PAIR_HPP


#include <iostream>

namespace ft
{
    template <class U, class V>
    class pair
    {
        public :
        	typedef U first_type;
        	typedef V second_type;
			U first;
			V second;
		pair() : first(), second() { return ; };
		pair (const first_type& a, const second_type& b) : first(a), second(b) { return ; };

		template <class U1, class V1>
		pair (const pair<U,V>& pr) : first(pr.first()), second(pr.second()) { return ; };

		~pair() { return ; };

		pair& operator= (const pair& pr) { this->first = pr.first; this->second= pr.second; return *this; };

		void swap(pair& pr) { ft::swap(this->first, pr.first); ft::swap(this->second, pr.second); };
    };

	template <class U, class V>
	pair<U, V> make_pair(U &a, V &b) {return (pair<U, V>(a, b));};
}

#endif
#include "../includes/includes.hpp"
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <iterator>
#include <__tree>
#define TESTED_TYPE int
#define TESTED_NAMESPACE ft
template <class T>
void show_vector(T& vector, std::string name)
{
	std::cout << "-----SHOW " << name <<"----" << std::endl;
	typename T::iterator it = vector.begin();
	typename T::iterator ite = vector.end();
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
}


template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const size_t size = vct.size();
	const size_t capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

//----------------------MAIN-----------------------
int		main(void)
{
	std::map<int, int> map;
	std::map<int, int>::iterator it = map.begin();

	return (0);
}
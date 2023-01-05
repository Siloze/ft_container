#include "../includes/includes.hpp"
#include <list>
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
void	printSize(ft::vector<T> const &vct, bool print_content = true)
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
		typename ft::vector<T>::const_iterator it = vct.begin();
		typename ft::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 4;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);
	std::list<TESTED_TYPE> lst2;
	for (int i = 1; i < 5; ++i)
		lst2.push_back(i * 5);
	std::cout << "FINAL STEP" << std::endl;
	vct.insert(vct.end(), lst2.rbegin(), lst2.rend());
	printSize(vct);
	std::cout << "MAIS NAN" << std::endl;
	return (0);
}
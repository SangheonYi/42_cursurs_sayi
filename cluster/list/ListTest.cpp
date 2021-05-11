# include <iostream>
# include <stdio.h>
# include "List.hpp"
# include <list>

/*
** 1. Construct
** 2. destructor
** 3. operator=
** 4. begin
** 5. end
** 6. rbegin
** 7. rend
** 8. empty
** 9. size
** 10. max_size
** 11. front
** 12. back
** 13. assign
** 14. push_front
** 15. pop_front
** 16. push_back
** 17. pop_back
** 18. insert
** 19. erase
** 20. swap
** 21. resize
** 22. clear
** 23. splice
** 24. remove
** 25. remove_if
** 26. unique
** 27. merge
** 28. sort
** 29. reverse
*/

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"
/*
template<typename T>
void cmpList(std::list<int>::iterator lit, ft::List<int>::iterator ft_lit) {
	std::cout << "lit :" << *lit << " ft:" << *lit2 << std::endl;

}

template <typename T>
 void    print_all_element(std::list<T> &ol, ft::List<T> &ml)
{
    std::cout << GREEN << "[ ";
    for (typename std::list<T>::iterator it = ol.begin(); it != ol.end(); it++)
        std::cout << *it << " ";
    std::cout << "]" << RESET << " ";

    std::cout << RED << "[ ";
    for (typename ft::List<T>::iterator it = ml.begin(); it != ml.end(); ++it)
        std::cout << *it << " ";
    std::cout << "]" << RESET << std::endl;
}

bool assignTest(std::list<int> list, std::list<int> list2) {
	std::list<int>::iterator lit = list.begin();
	std::list<int>::iterator lit2 = list2.begin();
	std::list<int>::iterator litEnd = list.end();
	bool isPass = true;

	while (lit != litEnd)
	{
		std::cout << "return :" << *lit << " " << *lit2 << std::endl;
		if (*lit++ != *lit2++)
			isPass = false;
	}
	return isPass;
}
 */
int main() {
	ft::List<int> list;
	ft::List<int> list2;
	ft::List<int>::iterator lit;
	ft::List<int>::iterator lit2;
	ft::List<int>::iterator litEnd;
	ft::List<int>::iterator litEnd2;
	bool isPass = true;
	int i = 0;
	while (i++ < 5)
		list.push_back(i);

// 1. Construct
	ft::List<int> *list3 = new ft::List<int>(list);
    int arr[] = {42, 18, 42, 18};
    std::list<int> range_ol(arr, arr + 4);
    ft::List<int> range_ml(arr, arr + 4);

// 2. destructor
	delete list3;

// 3. operator=
	list.push_back(0);
	list2 = list;

// 4. begin
	std::cout << "4. begin : " << (*list.begin() == *list2.begin()) << std::endl;
	std::cout << "return : " << *list.begin() << std::endl;
// 5. end
	std::cout << "5. end :" << (*list.end() == *list2.end()) << std::endl;
	std::cout << "return :" << *list.end() << std::endl;

// 6. rbegin
	std::cout << "6. rbegin :" << (*list.rbegin() == *list2.rbegin()) << std::endl;
	std::cout << "return :" << *list.rbegin() << std::endl;
/*

// 7. rend
	// std::cout << "7. rend :" << (*list.rend() == *list2.rend()) << std::endl;
	std::cout << "return :" << *(list.rend()) << std::endl;
	list.assign(list2.rbegin(), list2.rend());

// 8. empty
	std::cout << "8. empty :" << (list.empty() == list2.empty()) << std::endl;
	std::cout << "return :" << list.empty() << std::endl;

// 9. size
	std::cout << "9. size :" << (list.size() == list2.size()) << std::endl;
	std::cout << "return :" << list.size() << std::endl;

// 10. max_size
	std::cout << "10. max_size :" << (list.max_size() == list2.max_size()) << std::endl;
	std::cout << "return :" << list.max_size() << std::endl;

// 11. front
	std::cout << "11. front :" << (list.front() == list2.front()) << std::endl;
	std::cout << "return :" << list.front() << std::endl;

// 12. back
	std::cout << "12. back :" << (list.back() == list2.back()) << std::endl;
	std::cout << "return :" << list.back() << std::endl;

// 13. assign
	assignTest(list, list2);
	list.assign(5, 1);
	list2.assign(5, 1);
	assignTest(list, list2);

	std::cout << "13. assign :" << (list == list2) << std::endl; */
	// std::cout << "return :" << list << std::endl;
// 14. push_front
// 15. pop_front
// 16. push_back
// 17. pop_back
// 18. insert
// 19. erase
// 20. swap
// 21. resize
// 22. clear
// 23. splice
// 24. remove
// 25. remove_if
// 26. unique
// 27. merge
// 28. sort
// 29. reverse

}

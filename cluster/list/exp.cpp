#include <iostream>
#include <list>
#include "List.hpp"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

void    oneline(std::string const &title)
{
    std::cout << std::endl;
    std::cout << "-------------------- ";
    std::cout << title;
    std::cout << " -------------------- " << std::endl;
}

void    twoline(std::string const &title)
{
    std::cout << std::endl;
    std::cout << "==================== ";
    std::cout << title;
    std::cout << " ==================== " << std::endl;
}

template <typename T>
void    print_ori_my_value(std::string const &str, T ori, T my)
{
    std::cout << GREEN << "ori " << str << " = " << ori << RESET << " ";
    std::cout << RED <<" my " << str << " = " << my << RESET << std::endl;
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

// for remove if
bool    over_100(const int& val) { return (val >= 100); }
// for unique
bool    eqaul(const int& a, const int& b) { return (a == b); }
bool    diff_by_1(const int& a, const int& b) { return (a - b == -1); }
// for sort
bool    greater(const int& a, const int& b) { return (a > b); }
bool    less(const int& a, const int& b) { return (a < b); }

int main(void)
{
    std::list<int> ol;
    // ft::List<int> ml;
// gla list는 초기화 시 node가 하나 뿐이다.
    std::list<int>::iterator it = ol.begin();
    std::cout << "--" << *it++ << "--" << std::endl;
    std::cout << "--" << *it++ << "--" << std::endl;
    std::cout << "--" << *it++ << "--" << std::endl;
    ol.push_back(1);
    ol.push_back(2);
    ol.push_back(3);
    std::cout << std::endl;
    it = ol.begin();
    std::cout << "--" << *it++ << "--" << std::endl;
    std::cout << "--" << *it++ << "--" << std::endl;
    std::cout << "--" << *it++ << "--" << std::endl;
    std::cout << "--" << *it++ << "--" << std::endl;
    printf("%p\n%p", (void *) &*(ol.begin()), (void *) &*(ol.end()));
    printf("%p\n%p", (void *) &*(++ol.begin()), (void *) &*(ol.end()));
    // std::cout << RED <<" std " << *ol.begin() << *ol.end() << RESET << std::endl;
// std::list<int>::reverse_iterator it = ol.rbegin();
// *ml.begin() = 100;
//     std::cout << RED <<" my " << *(ml.end()) << RESET << std::endl;
}

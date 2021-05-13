#ifndef ISITERATOR
# define ISITERATOR
namespace ft
{
struct iter{};
struct not_iter{};

template<typename T> struct IsIterator {typedef iter value;};
template<> struct IsIterator<short> {typedef not_iter value;};
template<> struct IsIterator<int> {typedef not_iter value;};
template<> struct IsIterator<long> {typedef not_iter value;};
template<> struct IsIterator<char> {typedef not_iter value;};
template<> struct IsIterator<unsigned short> {typedef not_iter value;};
template<> struct IsIterator<unsigned int> {typedef not_iter value;};
template<> struct IsIterator<unsigned long> {typedef not_iter value;};
template<> struct IsIterator<unsigned char> {typedef not_iter value;};
}
#endif

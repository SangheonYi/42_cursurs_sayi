#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "Node.hpp"
/*
** @@T , add current member and fix implemented operators, +, -, +=, -=, base()
** https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html#_ZNKSt16reverse_iteratordeEv
*/

namespace ft
{
template<typename It>
class ReverseIterator:
	public It
{
protected:
	It	current;
public:
	using typename It::value_type;
	using typename It::pointer;
	using typename It::const_pointer;
	using typename It::reference;
	using typename It::const_reference;
	using typename It::difference_type;
public:
	ReverseIterator(): current() {}
	ReverseIterator(It const &it): current(it) {}
	ReverseIterator(ReverseIterator const &other): current(other.current) {}

	base() const {return (current);}
	ReverseIterator &operator=(ReverseIterator const &other) {
		this->p = other.p;
		return (*this);
	}

	reference operator*() {
		It tmp = current;
		return (*--tmp);
	}
	const_reference operator*() const {
		It tmp = current;
		return (*--tmp);
	}
	pointer operator->() {return &(operator*());}
	pointer operator->() {return &(operator*());}
	const_pointer operator->() const {return &(operator*());}
/*
** 	Increment / Decrement operator (postfix and prefix)
*/

	ReverseIterator operator++(int) {
		operator++();
		return (*this);
	}
	ReverseIterator &operator++() {
		It::operator--();
		return (*this);
	}
	ReverseIterator operator--(int) {
		operator--();
		return (tmp);
	}
	ReverseIterator &operator--() {
		It::operator++();
		return (*this);
	}
};
}

#endif

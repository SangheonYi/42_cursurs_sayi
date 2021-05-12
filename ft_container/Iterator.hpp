#ifndef ITERATOR_HPP
# define ITERATOR_HPP
# include <iostream>

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

	It base() const {return (current);}
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
	const_pointer operator->() const {return &(operator*());}
/*
** 	Increment / Decrement operator (postfix and prefix)
*/
	ReverseIterator operator++(int) {
		ReverseIterator __tmp = *this;
		--current;
		return (__tmp);
	}
	ReverseIterator &operator++() {
		--current;
		return (*this);
	}
	ReverseIterator operator--(int) {
		ReverseIterator __tmp = *this;
		++current;
		return (__tmp);
	}
	ReverseIterator &operator--() {
		++current;
		return (*this);
	}
/*
** +, -, +=, -=
*/
	ReverseIterator operator+(difference_type __n) const
	{ return ReverseIterator(current - __n); }
	ReverseIterator &operator+=(difference_type __n)
	{
		current -= __n;
		return *this;
	}
	ReverseIterator operator-(difference_type __n) const
	{ return ReverseIterator(current + __n); }
	ReverseIterator &operator-=(difference_type __n)
	{
		current += __n;
		return *this;
	}
};
}

#endif

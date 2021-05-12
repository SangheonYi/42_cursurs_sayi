#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <limits>
# include <cstring>
# include <memory>
# include "../Iterator.hpp"
# include "../FtUtil.hpp"

namespace ft
{
template<typename T>
class VectorIterator
{
public:
	typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const * const_pointer;
    typedef value_type& reference;
    typedef value_type const & const_reference;
    typedef std::ptrdiff_t difference_type;
protected:
	pointer p;
public:
	VectorIterator(): p(nullptr) {}
	VectorIterator(pointer p): p(p) {}
	VectorIterator(VectorIterator const &other): p(other.p) {}
	virtual ~VectorIterator() {}

	VectorIterator &operator=(VectorIterator const &other) {
		p = other.p;
		return (*this);
	}

	reference operator*() {
		return (*p);
	}
	const_reference operator*() const {
		return (*p);
	}
	pointer operator->() {
		return (p);
	}
	const_pointer operator->() const {
		return (p);
	}
    reference operator[](int val) {
		return (*(p + val));
	}
    const_reference operator[](int val) const {
		return (*(p + val));
	}

	VectorIterator operator++(int) {
		VectorIterator tmp(*this);
		++p;
		return (tmp);
	}
	VectorIterator &operator++() {
		++p;
		return (*this);
	}
	VectorIterator operator--(int) {
		VectorIterator tmp(*this);
		--p;
		return (tmp);
	}
	VectorIterator &operator--() {
		--p;
		return (*this);
	}

	VectorIterator &operator+=(int value) {
		p += value;
		return (*this);
	}
	VectorIterator operator+(int value) const {
		VectorIterator tmp(*this);
		return (tmp += value);
	}
	VectorIterator &operator-=(int value) {
		p -= value;
		return (*this);
	}
	VectorIterator operator-(int value) const {
		VectorIterator tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(VectorIterator const &other) const {
		return (p - other.p);
	}

	bool operator==(VectorIterator const &other) const {
		return (p == other.p);
	}
	bool operator!=(VectorIterator const &other) const {
		return (p != other.p);
	}
	bool operator<(VectorIterator const &other) const {
		return (p < other.p);
	}
	bool operator<=(VectorIterator const &other) const {
		return (p <= other.p);
	}
	bool operator>(VectorIterator const &other) const {
		return (p > other.p);
	}
	bool operator>=(VectorIterator const &other) const {
		return (p >= other.p);
	}
};

template<typename T, typename A = std::allocator<T>>
class Vector
{
public:
    typedef std::ptrdiff_t difference_type;
	typedef unsigned long size_type;
	typedef T value_type;
	typedef A allocator_type;
	typedef T* pointer;
	typedef T const * const_pointer;
	typedef T& reference;
	typedef T const & const_reference;
	typedef VectorIterator<value_type> iterator;
	typedef VectorIterator<value_type const> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;
	typedef ReverseIterator<const_iterator> const_reverse_iterator;
private:
	pointer m_container;
	size_type m_capacity;
	size_type m_size;
	allocator_type m_allocator;

	void copy_construct(size_type idx, const_reference val) {
		new(&m_container[idx]) value_type(val);
	}
public:
	Vector(const allocator_type &alloc = allocator_type()):
		m_container(nullptr), m_capacity(0), m_size(0), m_allocator(alloc) {
		m_container = m_allocator.allocate(0);
	}
	Vector(size_type n, const_reference val=value_type(), const allocator_type &alloc = allocator_type()):
		m_container(nullptr), m_capacity(0), m_size(0), m_allocator(alloc) {
		m_container = m_allocator.allocate(0);
		assign(n, val);
	}
	template <class InputIterator>
	Vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()):
		m_container(nullptr), m_capacity(0), m_size(0), m_allocator(alloc) {
		m_container = m_allocator.allocate(0);
		assign(first, last);
	}
	Vector(Vector const &other):
		m_container(nullptr), m_capacity(0), m_size(other.m_size), m_allocator(other.m_allocator) {
		reserve(other.m_capacity);
		std::memcpy(static_cast<void*>(m_container), static_cast<void*>(other.m_container), other.m_size * sizeof(value_type));
	}
	virtual ~Vector() {
		clear();
		if (m_container)
			m_allocator.deallocate(m_container, m_capacity);
	}

	Vector &operator=(Vector const &other) {
		if (m_container != nullptr)
			m_allocator.deallocate(m_container, m_capacity);
		m_allocator = other.m_allocator;
		m_size = other.m_size;
		m_capacity = other._capacity;
		m_container = m_allocator.allocate(0);
		assign(other.begin(), other.end());
		return (*this);
	}

	iterator begin(void) {
		return (iterator(m_container));
	}
	const_iterator begin(void) const {
		return (const_iterator(m_container));
	}
	reverse_iterator rbegin(void) {
		return (reverse_iterator(end()));
	}
	const_reverse_iterator rbegin(void) const {
		return (const_reverse_iterator(end()));
	}
	iterator end(void) {
		return (iterator(m_container + m_size));
	}
	const_iterator end(void) const {
		return (const_iterator(m_container + m_size));
	}
	reverse_iterator rend(void) {
		return (reverse_iterator(begin()));
	}
	const_reverse_iterator rend(void) const {
		return (const_reverse_iterator(begin()));
	}

	size_type size(void) const {
		return (m_size);
	}

	size_type max_size(void) const {
		return (m_allocator.max_size());
	}

	void resize(size_type size, value_type val=value_type()) {
		while (size > m_size)
			push_back(val);
		while (size < m_size)
			pop_back();
	}

	size_type capacity(void) const {
		return (m_capacity);
	}

	bool empty(void) const {
		return (m_size == 0);
	}

	void reserve(size_type size) {
		if (size > m_capacity) {
			value_type *tmp = m_allocator.allocate(size);
			if (m_container) {
				for (size_t i = 0; i < m_size; ++i)
					tmp[i] = m_container[i];
				m_allocator.deallocate(m_container, m_capacity);
			}
			m_container = tmp;
			m_capacity = size;// deallocate 전에 해야하나?
		}
	}

	reference operator[](size_type idx) {
		return (m_container[idx]);
	}
	const_reference operator[](size_type idx) const {
		return (m_container[idx]);
	}
	reference at(size_type __n) {
		if (__n >= m_size)
			throw std::out_of_range("vector::_M_range_check: __n ");
		return (m_container[__n]);
	}
	const_reference at(size_type __n) const {
		if (__n >= m_size)
			throw std::out_of_range("vector::_M_range_check: __n ");
		return (m_container[__n]);
	}

	reference front(void) {
		return (m_container[0]);
	}
	const_reference front(void) const {
		return (m_container[0]);
	}
	reference back(void) {
		return (m_container[m_size - 1]);
	}
	const_reference back(void) const {
		return (m_container[m_size - 1]);
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last){
		clear();
		insert(begin(), first, last);
	}
	void assign(size_type size, const_reference val) {
		clear();
		insert(begin(), size, val);
	}

	void push_back(const_reference val) {
		insert(end(), val);
	}
	void pop_back(void) {
		erase(--end());
	}

	iterator insert(iterator position, const_reference val) {
		size_type i = 0;
		iterator it = begin();
		while (it + i != position && i < m_size)
			i++;
		if (m_capacity == 0)
			reserve(1);
		else if (m_size >= m_capacity)
			reserve(m_capacity * 2);
		size_type j = m_capacity - 1;
		while (j > i)
		{
			m_container[j] = m_container[j - 1];
			j--;
		}
		m_container[i] = val;
		m_size++;
		return (iterator(&m_container[i]));
	}
	void insert(iterator position, size_type size, const_reference val) {
		while (size--)
			position = insert(position, val);
	}
	void insert(iterator position, iterator first, iterator last) {
		while (first != last)
		{
			position = insert(position, *first) + 1;
			first++;
		}
	}

	iterator erase(iterator position) {
		iterator iter = position;
		while (iter + 1 != end())
		{
			*iter = *(iter + 1);
			iter++;
		}
		m_size--;
		return (iterator(position));
	}
	iterator erase(iterator first, iterator last) {
		while (first != last)
		{
			erase(first);
			last--;
		}
		return (iterator(first));
	}

	void swap(Vector &other) {
		ft::swap(m_container, other.m_container);
		ft::swap(m_capacity, other.m_capacity);
		ft::swap(m_size, other.m_size);
	}

	void clear(void) {
		erase(begin(), end());
	}
};

template<typename T>
bool operator==(Vector<T> const &lhs, Vector<T> const &rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i++)
		if (lhs[i] != rhs[i])
			return (false);
	return (true);
}

template<typename T>
bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (!(lhs == rhs));
}

template<typename T>
bool operator<(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator<=(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (!(rhs < lhs));
}

template<typename T>
bool operator>(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (rhs < lhs);
}

template<typename T>
bool operator>=(Vector<T> const &lhs, Vector<T> const &rhs) {
	return (!(lhs < rhs));
}

template<typename T>
void swap(Vector<T> &x, Vector<T> &y) {
	x.swap(y);
}
}

#endif

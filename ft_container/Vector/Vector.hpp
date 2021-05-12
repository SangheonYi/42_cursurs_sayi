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
		this->p = other.p;
		return (*this);
	}

	reference operator*() {
		return (*this->p);
	}
	const_reference operator*() const {
		return (*this->p);
	}
	pointer operator->() {
		return (this->p);
	}
	const_pointer operator->() const {
		return (this->p);
	}
    reference operator[](int val) {
		return (*(this->p + val));
	}
    const_reference operator[](int val) const {
		return (*(this->p + val));
	}

	VectorIterator operator++(int) {
		VectorIterator tmp(*this);
		++this->p;
		return (tmp);
	}
	VectorIterator &operator++() {
		++this->p;
		return (*this);
	}
	VectorIterator operator--(int) {
		VectorIterator tmp(*this);
		--this->p;
		return (tmp);
	}
	VectorIterator &operator--() {
		--this->p;
		return (*this);
	}

	VectorIterator &operator+=(int value) {
		this->p += value;
		return (*this);
	}
	VectorIterator operator+(int value) const {
		VectorIterator tmp(*this);
		return (tmp += value);
	}
	VectorIterator &operator-=(int value) {
		this->p -= value;
		return (*this);
	}
	VectorIterator operator-(int value) const {
		VectorIterator tmp(*this);
		return (tmp -= value);
	}
	difference_type operator-(VectorIterator const &other) const {
		return (this->p - other.p);
	}

	bool operator==(VectorIterator const &other) const {
		return (this->p == other.p);
	}
	bool operator!=(VectorIterator const &other) const {
		return (this->p != other.p);
	}
	bool operator<(VectorIterator const &other) const {
		return (this->p < other.p);
	}
	bool operator<=(VectorIterator const &other) const {
		return (this->p <= other.p);
	}
	bool operator>(VectorIterator const &other) const {
		return (this->p > other.p);
	}
	bool operator>=(VectorIterator const &other) const {
		return (this->p >= other.p);
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
		new(&this->m_container[idx]) value_type(val);
	}
public:
	Vector(const allocator_type &alloc = allocator_type()):
		m_container(nullptr), m_capacity(0), m_size(0), m_allocator(alloc) {
		m_container = m_allocator.allocate(0);
	}
	Vector(size_type n, const_reference val=value_type(), const allocator_type &alloc = allocator_type()):
		m_container(nullptr), m_capacity(0), m_size(0), m_allocator(alloc) {
		m_container = m_allocator.allocate(0);
		this->assign(n, val);
	}
	template <class InputIterator>
	Vector (InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type()):
		m_container(nullptr), m_capacity(0), m_size(0), m_allocator(alloc) {
		m_container = m_allocator.allocate(0);
		this->assign(first, last);
	}
	Vector(Vector const &other):
		m_container(nullptr), m_capacity(0), m_size(other.m_size), m_allocator(other.m_allocator) {
		this->reserve(other.m_capacity);
		std::memcpy(static_cast<void*>(this->m_container), static_cast<void*>(other.m_container), other.m_size * sizeof(value_type));
	}
	virtual ~Vector() {
		this->clear();
		if (this->m_container)
			this->m_allocator.deallocate(this->m_container, this->m_capacity);
	}

	Vector &operator=(Vector const &other) {
		if (this->m_container != nullptr)
			this->m_allocator.deallocate(this->m_container, this->m_capacity);
		this->m_allocator = other.m_allocator;
		this->m_sizw = other.m_sizw;
		this->m_capacity = other._capacity;
		this->m_container = this->m_allocator.allocate(0);
		assign(other.begin(), other.end());
		return (*this);
	}

	iterator begin(void) {
		return (iterator(this->m_container));
	}
	const_iterator begin(void) const {
		return (const_iterator(this->m_container));
	}
	reverse_iterator rbegin(void) {
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}
	iterator end(void) {
		return (iterator(this->m_container + this->m_size));
	}
	const_iterator end(void) const {
		return (const_iterator(this->m_container + this->m_size));
	}
	reverse_iterator rend(void) {
		return (reverse_iterator(this->begin()));
	}
	const_reverse_iterator rend(void) const {
		return (const_reverse_iterator(this->begin()));
	}

	size_type size(void) const {
		return (this->m_size);
	}

	size_type max_size(void) const {
		return (ft::min((size_type) std::numeric_limits<difference_type>::max(),
						std::numeric_limits<size_type>::max() / sizeof(value_type)));
	}

	void resize(size_type size, value_type val=value_type()) {
		while (n > _length)
			push_back(val);
		while (n < _length)
			pop_back();
	}

	size_type capacity(void) const {
		return (this->m_capacity);
	}

	bool empty(void) const {
		return (this->m_size == 0);
	}

	void reserve(size_type size) {
		if (size > this->m_capacity) {
			value_type *tmp = this->m_allocator.allocate(size);
			if (this->m_container) {
				for (size_t i = 0; i < this->m_size; ++i)
					tmp[i] = this->m_container[i];
				this->m_allocator.deallocate(this->m_container, this->m_capacity);
			}
			this->m_container = tmp;
			this->m_capacity = size;
		}
	}

	reference operator[](size_type idx) {
		return (this->m_container[idx]);
	}
	const_reference operator[](size_type idx) const {
		return (this->m_container[idx]);
	}
	reference at(size_type __n) {
		if (__n >= this->m_size)
			throw std::out_of_range("vector::_M_range_check: __n ");
		return (this->m_container[__n]);
	}
	const_reference at(size_type __n) const {
		if (__n >= this->m_size)
			throw std::out_of_range("vector::_M_range_check: __n ");
		return (this->m_container[__n]);
	}

	reference front(void) {
		return (this->m_container[0]);
	}
	const_reference front(void) const {
		return (this->m_container[0]);
	}
	reference back(void) {
		return (this->m_container[this->m_size - 1]);
	}
	const_reference back(void) const {
		return (this->m_container[this->m_size - 1]);
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last){
		size_t length = last - first;
		if (length > this->m_capacity)
			this->reserve(length);
		size_t i = 0;
		while (first != last) {
			if (i >= this->m_size)
				this->copy_construct(i, *first);
			else
				this->m_container[i] = *first;
			++first;
			++i;
		}
		while (i < this->m_size)
			this->m_container[i++].value_type::~value_type();
		this->m_size = length;
	}
	void assign(size_type size, const_reference val) {
		if (size > this->m_capacity)
			this->reserve(size);
		size_t i = 0;
		while (i < size) {
			if (i >= this->m_size)
				this->copy_construct(i, val);
			else
				this->m_container[i] = val;
			++i;
		}
		while (i < this->m_size)
			this->m_container[i++].value_type::~value_type();
		this->m_size = size;
	}

	void push_back(const_reference val) {
		if (this->m_size == this->m_capacity)
			this->reserve(this->m_capacity * 2);
		new(&this->m_container[this->m_size++]) value_type(val);
	}
	void pop_back(void) {
		this->m_container[--this->m_size].value_type::~value_type();
	}

	iterator insert(iterator position, const_reference val) {
		this->insert(position, 1, val);
		return (++position);
	}
	void insert(iterator position, size_type size, const_reference val) {
		iterator it = this->begin();
		if (this->m_size + size >= this->m_capacity)
			this->reserve(this->m_size + size);
		size_type i = 0;
		while (it != position) {
			++it;
			++i;
		}
		// std::memmove
		for (size_type j = this->m_size; j >= 1 && j >= i; j--)
			this->copy_construct(i + j + size - 1, this->m_container[j - 1]);
		for (size_type j = 0; j < size; j++)
			this->copy_construct(i + j, val);
		this->m_size += size;
	}
	void insert(iterator position, iterator first, iterator last) {
		size_type size = last - first;
		iterator it = this->begin();
		if (this->m_size + size >= this->m_capacity)
			this->reserve(this->m_size + size);
		size_type i = 0;
		while (it != position) {
			++it;
			++i;
		}
		// std::memmove
		for (size_type j = this->m_size - 1; j > i + 1; j++)
			this->copy_construct(i + j + size, this->m_container[ + j - 1]);
		for (size_type j = 0; j < size; j++)
			this->copy_construct(i + j, *first++);
		this->m_size += size;
	}

	iterator erase(iterator position) {
		iterator iter = position;
		while (iter + 1 != end())
		{
			*iter = *(iter + 1);
			iter++;
		}
		this->m_size--;
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
		ft::swap(this->m_container, other.m_container);
		ft::swap(this->m_capacity, other.m_capacity);
		ft::swap(this->m_size, other.m_size);
	}

	void clear(void) {
		erase(this->begin(), this->end());
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

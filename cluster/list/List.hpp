#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include "Node.hpp"
# include "../Iterator.hpp"
# include "Algorithm.hpp"

namespace ft
{
template<typename T, typename N>
class ListIterator
{
public:
	typedef T value_type;
    typedef value_type* pointer;
    typedef value_type const * const_pointer;
    typedef value_type& reference;
    typedef value_type const & const_reference;
	typedef N node_type;
	typedef node_type* node_pointer;
    typedef std::ptrdiff_t difference_type;
protected:
	node_pointer p;
public:
	ListIterator(): p(nullptr) {}
	ListIterator(node_pointer p): p(p) {}
	ListIterator(ListIterator const &other): p(other.p) {}
	virtual ~ListIterator() {}

	node_pointer &ptr(void) {
		return (this->p);
	}

	node_pointer as_node(void) const {
		return (this->p);
	}

	reference operator*() {
		return (this->p->value());
	}
	const_reference operator*() const {
		return (this->p->value());
	}
	pointer operator->() {
		return (&this->p->value());
	}
	const_pointer operator->() const {
		return (&this->p->value());
	}

	ListIterator &operator++() {
		this->p = this->p->next();
		return (*this);
	}
	ListIterator operator++(int) {
		ListIterator tmp(*this);
		this->p = this->p->next();
		return (tmp);
	}
	ListIterator &operator--() {
		this->p = this->p->previous();
		return (*this);
	}
	ListIterator operator--(int) {
		ListIterator tmp(*this);
		this->p = this->p->previous();
		return (tmp);
	}

	ListIterator &operator+=(int value) {
		if (value > 0) {
			for (int i = 0; i < value; i++)
				this->p = this->p->next();
		} else {
			for (int i = value; i > 0; i--)
				this->p = this->p->previous();
		}
	}
	ListIterator operator+(int value) const {
		ListIterator tmp(*this);
		return (tmp += value);
	}
	ListIterator &operator-=(int value) {
		operator+=(-value);
		return (*this);
	}
	ListIterator operator-(int value) const {
		ListIterator tmp(*this);
		return (tmp -= value);
	}

	bool operator==(ListIterator const &other) const {
		return (this->p == other.p);
	}
	bool operator!=(ListIterator const &other) const {
		return (this->p != other.p);
	}
	bool operator<(ListIterator const &other) const {
		return (this->p < other.p);
	}
	bool operator<=(ListIterator const &other) const {
		return (this->p <= other.p);
	}
	bool operator>(ListIterator const &other) const {
		return (this->p > other.p);
	}
	bool operator>=(ListIterator const &other) const {
		return (this->p >= other.p);
	}
};

template<typename T>
class List
{
public:
    typedef std::ptrdiff_t difference_type;
	typedef unsigned long size_type;
	typedef T value_type;
	typedef Node<value_type> node_type;
	typedef node_type* node_pointer;
	typedef value_type* pointer;
	typedef value_type const *const_pointer;
	typedef value_type& reference;
	typedef value_type const &const_reference;
	typedef ListIterator<value_type, node_type> iterator;
	typedef ListIterator<value_type const, node_type const> const_iterator;
	typedef ReverseIterator<iterator> reverse_iterator;
	typedef ReverseIterator<const_iterator> const_reverse_iterator;
private:


	void _init_list(void) {
		this->_tail = this->_head = new Node<value_type>(value_type());
	}

	void reset_list(void) {
		this->_head = this->_tail;
		this->_tail->previous() = this->_tail;
		this->_tail->next() = this->_tail;
	}
public:
	node_pointer _head;
	node_pointer _tail;
	size_type _list_size;
	List():
		_head(nullptr), _tail(nullptr), _list_size(0) {
		this->_init_list();
		// printf("new node: %p\n", (void *)this->_head);
		// printf("new node: %p\n", (void *)this->_tail);

	}
	List(size_type n, const_reference val=value_type()):
		_head(nullptr), _tail(nullptr), _list_size(0) {
		this->_init_list();
		this->assign(n, val);
	}
	template<typename InputIterator>

	List(InputIterator first, InputIterator last):
		_head(nullptr), _tail(nullptr), _list_size(0) {
		this->_init_list();
		this->assign(first, last);
	}
	List(List const &other):
		_head(nullptr), _tail(nullptr), _list_size(0) {
		this->_init_list();
		this->assign(other.begin(), other.end());
	}
	virtual ~List() {
		this->clear();
		delete this->_tail;
	}

	List &operator=(List const &other) {
		this->assign(other.begin(), other.end());
		return (*this);
	}

	iterator begin(void) {
		return (iterator(this->_head));
	}
	const_iterator begin(void) const {
		return (const_iterator(this->_head));
	}
	reverse_iterator rbegin(void) {
		return (reverse_iterator(this->end()));
	}
	const_reverse_iterator rbegin(void) const {
		return (const_reverse_iterator(this->end()));
	}
	iterator end(void) {
		return (iterator(this->_tail));
	}
	const_iterator end(void) const {
		return (const_iterator(this->_tail));
	}
	reverse_iterator rend(void) {
		return (reverse_iterator(this->begin()));
	}
	const_reverse_iterator rend(void) const {
		return (const_reverse_iterator(this->begin()));
	}

	bool empty(void) const {
		return (this->_list_size == 0);
	}
	size_type size(void) const {
		return (this->_list_size);
	}
	size_type max_size(void) const {
		return (ft::min((size_type) std::numeric_limits<difference_type>::max(),
						std::numeric_limits<size_type>::max() / (sizeof(node_type) - sizeof(pointer))));
	}

	reference front() {
		return (this->_head->value());
	}
	const_reference front() const {
		return (this->_head->value());
	}
	reference back() {
		return (this->_tail->previous()->value());
	}
	const_reference back() const {
		return (this->_tail->previous()->value());
	}

	template<typename InputIterator>
	void assign(InputIterator first, InputIterator last) {
		this->clear();
		while (first != last)
			this->push_back(*first++);
	}
/* 	void assign(const_iterator first, const_iterator last) {
		this->clear();
		while (first != last)
			this->push_back(*first++);
	} */
	void assign(size_type size, const_reference val) {
		this->clear();
		for (size_type i = 0; i < size; i++)
			this->push_back(val);
	}

	void push_front(const_reference val) {
		node_pointer tmp = new node_type(val);
		this->_head->insert_node(tmp);
		this->_head = tmp;
		++this->_list_size;
	}
	void pop_front(void) {
		if (this->_list_size >= 1) {
			node_pointer tmp = this->_head->next();
			this->_head->disconnect();
			delete this->_head;
			this->_head = tmp;
			--this->_list_size;
		}
	}
	void push_back(const_reference val) {
		node_pointer tmp = new node_type(val);
		this->_tail->insert_node(tmp);
		if (this->_list_size == 0)
			this->_head = tmp;
		++this->_list_size;
	}
	void pop_back(void) {
		if (this->_list_size >= 1) {
			node_pointer tmp = this->_tail->previous();
			this->_tail->previous()->disconnect();
			delete tmp;
			--this->_list_size;
			if (this->_list_size == 0)
				this->_head = this->_tail;
		}
	}

	iterator insert(iterator position, const_reference val) {
		if (position == this->begin()) {
			this->push_front(val);
			return (this->begin());
		} else if (position == this->end()) {
			this->push_back(val);
			return (this->end());
		}
		node_pointer newNode = new node_type(val);
		position.as_node()->insert_node(newNode);
		++this->_list_size;
		return (iterator(newNode));
	}
	void insert(iterator position, size_type size, const_reference val) {
		for (size_type i = 0; i < size; i++)
			this->insert(position, val);
	}
	void insert(iterator position, iterator first, List::iterator last) {
		while (first != last)
			this->insert(position, *first++);
	}

	iterator erase(iterator position) {
		if (position == this->begin()) {
			this->pop_front();
			return (this->begin());
		} else if (position == this->end()) {
			this->pop_back();
			return (this->end());
		}
		node_pointer next = position.as_node()->next();
		position.as_node()->disconnect();
		delete position.as_node();
		--this->_list_size;
		return (iterator(next));
	}
	iterator erase(iterator first, iterator last) {
		while (first != last)
			this->erase(first++);
		return (first);
	}

	void swap(List &other) {
		ft::swap(this->_head, other._head);
		ft::swap(this->_tail, other._tail);
		ft::swap(this->_list_size, other._list_size);
	}

	void resize(size_type n, value_type val=value_type()) {
		if (n == 0)
			this->clear();
		else if (n < this->_list_size) {
			size_t i = 0;
			iterator first = this->begin();
			while (i < n) {
				++i;
				++first;
			}
			this->erase(first, this->end());
		} else
			this->insert(this->end(), n - this->_list_size, val);
	}

	void clear(void) {
		this->erase(this->begin(), this->end());
		this->reset_list();
	}

	void splice(iterator position, List &x) {
		this->splice(position, x, x.begin(), x.end());
	}
	void splice(iterator position, List &x, iterator it) {
		iterator next = it;
		this->splice(position, x, it, ++next);
	}
	void splice(iterator position, List &x, iterator first, iterator last) {
		while (first != last) {
			node_pointer tmp = first++.as_node();
			if (tmp == x._head)
				x._head = tmp->next();
			tmp->disconnect();
			position.as_node()->insert_node(tmp);
			if (position.as_node() == this->_head)
				this->_head = tmp;
			++this->_list_size;
			--x._list_size;
		}
		if (x._list_size == 0)
			x.reset_list();
	}

	void remove(const_reference val) {
		iterator first = this->begin();
		iterator last = this->end();

		while (first != last) {
			if (*first == val)
				first = this->erase(first);
			else
				++first;
		}
	}
	template<typename Predicate>
	void remove_if(Predicate pred) {
		iterator first = this->begin();
		iterator last = this->end();

		while (first != last) {
			if ((*pred)(*first))
				first = this->erase(first);
			else
				++first;
		}
	}

	void unique(void) {
		this->unique(&equal<value_type>);
	}
	template<typename BinaryPredicate>
	void unique(BinaryPredicate binary_pred) {
		iterator previous = this->begin();
		iterator next = previous;
		iterator last = this->end();

		while (next != last) {
			++next;
			if ((*binary_pred)(*previous, *next)) {
				this->erase(next);
				next = previous;
			} else
				previous = next;
		}
	}

	void merge(List &x) {
		if (&x == this)
			return ;
		this->merge(x, &less_than<value_type>);
	}
	template<typename Compare>
	void merge(List &x, Compare comp) {
		if (&x == this)
			return ;
		if (this->_list_size == 0) {
			this->assign(x.begin(), x.end());
			x.clear();
			return ;
		}
		iterator f1 = this->begin();
		iterator e1 = this->end();
		iterator f2 = x.begin();
		iterator e2 = x.end();

		while (f1 != e1 && f2 != e2) {
			if ((*comp)(*f2, *f1)) {
				x._head = f2.as_node()->next();
				--x._list_size;
				f2.as_node()->disconnect();
				f1.as_node()->insert_node(f2.as_node());
				if (f1 == this->begin())
					this->_head = this->_head->previous();
				++this->_list_size;
				f2 = x.begin();
			} else
				++f1;
		}
		this->splice(e1, x);
	}

	void sort(void) {
		if (this->_list_size <= 1)
			return ;
		this->sort(less_than<value_type>);
	}
	template<typename Compare>
	void sort(Compare comp) {
		if (this->_list_size <= 1)
			return ;
		iterator first = this->begin();
		iterator last = this->end();
		iterator next;
		iterator tmp;

		while (first != last) {
			next = first;
			while (++next != last) {
				if (comp(*next, *first)) {
					if (first.as_node() == this->_head)
						this->_head = next.as_node();
					first.as_node()->swap(next.as_node());
					tmp = next;
					next = first;
					first = tmp;
				}
			}
			++first;
		}
	}

	void reverse(void) {
		if (this->_list_size <= 1)
			return ;
		iterator begin = this->begin();
		iterator end = --this->end();

		size_t limit = this->_list_size / 2;
		for (size_t i = 0; i < limit; ++i) {
			begin++.as_node()->swap(end--.as_node());
		}
		while (end.as_node()->previous())
			--end;
		this->_head = end.ptr();
	}
};

template<typename value_type>
bool operator==(List<value_type> const &lhs, List<value_type> const &rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	typename List<value_type>::const_iterator first1 = lhs.begin();
	typename List<value_type>::const_iterator last1 = lhs.end();
	typename List<value_type>::const_iterator first2 = rhs.begin();
	typename List<value_type>::const_iterator last2 = rhs.end();
	while (first1 != last1)
		if (*first1++ != *first2++)
			return (false);
	return (true);
}

template<typename T>
bool operator!=(List<T> const &lhs, List<T> const &rhs) {
	return (!(lhs == rhs));
}

template<typename T>
bool operator<(List<T> const &lhs, List<T> const &rhs) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template<typename T>
bool operator<=(List<T> const &lhs, List<T> const &rhs) {
	return (!(rhs < lhs));
}

template<typename T>
bool operator>(List<T> const &lhs, List<T> const &rhs) {
	return (rhs < lhs);
}

template<typename T>
bool operator>=(List<T> const &lhs, List<T> const &rhs) {
	return (!(lhs < rhs));
}

template<typename T>
void swap(List<T> &x, List<T> &y) {
	x.swap(y);
}
}

#endif

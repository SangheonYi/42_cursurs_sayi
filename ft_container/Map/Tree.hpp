#ifndef TREE_HPP
# define TREE_HPP

# include <utility>
# include "Iterator.hpp"

namespace ft
{
template<typename T, typename N>
class TreeIterator: IteratorTrait
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

	void previous() {
		if (this->p->left) {
			this->p = this->p->left;
			while (this->p->right)
				this->p = this->p->right;
		} else
			this->p = this->p->parent;
	}
	void next() {
		if (this->p->right) {
			this->p = this->p->right;
			while (this->p->left)
				this->p = this->p->left;
		} else {
			node_pointer tmp = this->p;
			this->p = this->p->parent;
			while (this->p->left != tmp)
			{
				tmp = this->p;
				this->p = this->p->parent;
			}
		}
	}
public:
	TreeIterator(): p(nullptr) {}
	TreeIterator(node_pointer p): p(p) {}
	TreeIterator(TreeIterator const &other): p(other.p) {}
	virtual ~TreeIterator() {}

	node_pointer as_node(void) const {
		return (this->p);
	}

	TreeIterator &operator=(TreeIterator const &other) {
		this->p = other.p;
		return (*this);
	}

	reference operator*() {
		return (this->p->value);
	}
	const_reference operator*() const {
		return (this->p->value);
	}
	pointer operator->() {
		return (&this->p->value);
	}
	const_pointer operator->() const {
		return (&this->p->value);
	}

	TreeIterator operator++(int) {
		TreeIterator tmp(*this);
		this->next();
		return (tmp);
	}
	TreeIterator &operator++() {
		this->next();
		return (*this);
	}
	TreeIterator operator--(int) {
		TreeIterator tmp(*this);
		this->previous();
		return (tmp);
	}
	TreeIterator &operator--() {
		this->previous();
		return (*this);
	}

	TreeIterator &operator+=(int value) {
		if (value > 0) {
			for (int i = 0; i < value; i++)
				this->next();
		} else {
			for (int i = value; i > 0; i--)
				this->previous();
		}
		return (*this);
	}
	TreeIterator operator+(int value) const {
		TreeIterator tmp(*this);
		return (tmp += value);
	}
	TreeIterator &operator-=(int value) {
		operator+=(-value);
		return (*this);
	}
	TreeIterator operator-(int value) const {
		TreeIterator tmp(*this);
		return (tmp -= value);
	}

	bool operator==(TreeIterator const &other) const {
		return (this->p == other.p);
	}
	bool operator!=(TreeIterator const &other) const {
		return (this->p != other.p);
	}
	bool operator<(TreeIterator const &other) const {
		return (this->p < other.p);
	}
	bool operator<=(TreeIterator const &other) const {
		return (this->p <= other.p);
	}
	bool operator>(TreeIterator const &other) const {
		return (this->p > other.p);
	}
	bool operator>=(TreeIterator const &other) const {
		return (this->p >= other.p);
	}
};

/**
 * Simple Binary Tree
 **/
template <typename T, typename Compare>
class Tree
{
public:
	typedef size_t size_type;
	typedef T value_type;
	typedef value_type* pointer;
	typedef value_type const * const_pointer;
	typedef value_type& reference;
	typedef value_type const & const_reference;
	struct Node
	{
		value_type value;
		Node *parent;
		Node *left;
		Node *right;

		Node(const_reference val=value_type()):
			value(val), parent(nullptr), left(nullptr), right(nullptr) {}
		Node(Node const &other):
			value(other.value), parent(nullptr), left(nullptr), right(nullptr) {}
	};
	typedef Node* node_pointer;
protected:
	node_pointer m_root;
	node_pointer m_begin;
	node_pointer m_end;
	Compare m_comp;

	void unbound_node(node_pointer node) {
		if (!node)
			return ;
		node->parent = nullptr;
		node->left = nullptr;
		node->right = nullptr;
	}

	void make_bounds(void) {
		this->m_begin = new Node();
		this->m_end = this->m_begin;
		this->m_root = this->m_end;
	}

	void repair_bounds(void) {
		node_pointer tmp = this->m_root;
		while (tmp->left)
			tmp = tmp->left;
		this->m_begin = tmp;
		tmp = this->m_root;
		while (tmp->right)
			tmp = tmp->right;
		tmp->right = this->m_end;
		this->m_end->parent = tmp;
	}

	template<typename Tp>
	node_pointer find_node(Tp const &val, node_pointer node) {
		if (node == this->m_end || !node)
			return (nullptr);
		bool comp_left = this->m_comp(val, node->value);
		if (!comp_left && !this->m_comp(node->value, val))
			return (node);
		if (comp_left)
			return (this->find_node(val, node->left));
		return (this->find_node(val, node->right));
	}

	void insert_node_at(node_pointer node, node_pointer new_node) {
		if (this->m_comp(new_node->value, node->value)) {
			if (node->left) {
				this->insert_node_at(node->left, new_node);
				return ;
			} else
				node->left = new_node;
		} else {
			if (node->right) {
				this->insert_node_at(node->right, new_node);
				return ;
			} else
				node->right = new_node;
		}
		new_node->parent = node;
	}

	void copy_node_recurse(node_pointer *destination, node_pointer source, node_pointer end) {
		if (!source)
			return ;
		*destination = new Node(*source);
		if (source->left) {
			copy_node_recurse(&(*destination)->left, source->left, end);
			(*destination)->left->parent = *destination;
		}
		if (source->right && source->right != end) {
			copy_node_recurse(&(*destination)->right, source->right, end);
			(*destination)->right->parent = *destination;
		}
	}

	node_pointer erase_node(node_pointer node) {
		if (!node)
			return (node);
		node_pointer ret = node;
		// no children
		if (!node->left && !node->right) {
			if (node == this->m_root) {
				this->m_root = this->m_begin = this->m_end;
				this->unbound_node(this->m_end);
			}
			if (node->parent) {
				if (node->parent->left == node)
					node->parent->left = nullptr;
				else
					node->parent->right = nullptr;
			}
			ret = node->parent;
			delete node;
		// one child (right)
		} else if (!node->left) {
			if (node->parent) {
				if (node->parent->left == node)
					node->parent->left = node->right;
				else
					node->parent->right = node->right;
			}
			node->right->parent = node->parent;
			if (node == this->m_root)
				this->m_root = node->right;
			ret = node->right;
			delete node;
		// one child (left)
		} else if (!node->right) {
			if (node->parent) {
				if (node->parent->left == node)
					node->parent->left = node->left;
				else
					node->parent->right = node->left;
			}
			node->left->parent = node->parent;
			if (node == this->m_root)
				this->m_root = node->left;
			ret = node->parent;
			delete node;
		// two children
		} else {
			node_pointer tmp = node->right; // find minimal value of right sub tree
			while (tmp && tmp->left != nullptr)
				tmp = tmp->left;
			if (node->parent) {
				if (node->parent->left == node)
					node->parent->left = tmp;
				else
					node->parent->right = tmp;
			}
			tmp->parent = node->parent;
			node->value.value_type::~value_type();
			new(&node->value) value_type(tmp->value);
			if (node == this->m_root)
				this->m_root = node;
			node->right = erase_node(node->right); // delete the duplicate node
			ret = node;
		}
		return (ret);
	}

	void delete_recurse(node_pointer node) {
		if (!node || node == this->m_end)
			return ;
		delete_recurse(node->left);
		delete_recurse(node->right);
		delete node;
	}
public:
	Tree():
		m_root(nullptr), m_comp() {
		this->make_bounds();
	}
	Tree(Compare const &comp):
		m_root(nullptr), m_comp(comp) {
		this->make_bounds();
	}
	Tree(Tree const &other):
		m_root(other.m_root), m_comp(other.m_comp) {
		this->make_bounds();
		this->copy(other);
	}
	virtual ~Tree() {
		this->make_empty();
		delete this->m_end;
	}

	Tree &operator=(Tree const &other) {
		if (this->m_root != this->m_end)
			this->make_empty();
		this->m_comp = other.m_comp;
		this->copy(other);
		return (*this);
	}

	void copy(Tree const &other) {
		if (other.m_root == other.m_end)
			return ;
		this->m_root = new Node(*other.m_root);
		if (other.m_root->left) {
			this->copy_node_recurse(&this->m_root->left, other.m_root->left, other.m_end);
			this->m_root->left->parent = this->m_root;
		}
		if (other.m_root->right) {
			this->copy_node_recurse(&this->m_root->right, other.m_root->right, other.m_end);
			this->m_root->right->parent = this->m_root;
		}
		this->repair_bounds();
	}

	node_pointer insert(const_reference val) {
		node_pointer new_node = new Node(val);
		if (this->m_root == this->m_end)
			this->m_root = new_node;
		else {
			if (this->m_end->parent)
				this->m_end->parent->right = nullptr;
			this->insert_node_at(this->m_root, new_node);
		}
		this->repair_bounds();
		return (new_node);
	}

	node_pointer insert(node_pointer hint, const_reference val) {
		if (!hint || this->m_root == this->m_end
			|| (hint->parent && (m_comp(val, hint->parent->value) || m_comp(hint->parent->value, val))))
			return (this->insert(val));
		node_pointer new_node = new Node(val);
		if (this->m_end->parent)
			this->m_end->parent->right = nullptr;
		this->insert_node_at(hint, new_node);
		this->repair_bounds();
		return (new_node);
	}

	template<typename Tp>
	node_pointer find(Tp const &val) {
		return (this->find_node(val, this->m_root));
	}

	template<typename Tp>
	node_pointer find(node_pointer hint, Tp const &val) {
		if (!hint)
			return (this->find_node(val, this->m_root));
		if (!m_comp(hint->value, val) && !m_comp(val, hint->value))
			return (hint);
		return (this->find_node(val, hint));
	}

	node_pointer erase(node_pointer node) {
		if (this->m_end->parent)
			this->m_end->parent->right = nullptr;
		node_pointer next = this->erase_node(node);
		this->repair_bounds();
		return (next);
	}

	template<typename Tp>
	size_type erase(Tp const &key) {
		node_pointer node = nullptr;
		size_type total = 0;

		if (this->m_end->parent)
			this->m_end->parent->right = nullptr;
		while ((node = this->find(key))) {
			this->erase_node(node);
			total++;
		}
		this->repair_bounds();
		return (total);
	}

	Compare key_compare(void) const {
		return (this->m_comp);
	}

	node_pointer begin(void) const {
		return (this->m_begin);
	}

	node_pointer end(void) const {
		return (this->m_end);
	}

	void make_empty(void) {
		this->delete_recurse(this->m_root);
		this->m_end->parent = nullptr;
		this->m_end->left = nullptr;
		this->m_end->right = nullptr;
		this->m_begin = this->m_root = this->m_end;
	}

	void swap(Tree &other) {
		ft::swap(this->m_root, other.m_root);
		ft::swap(this->m_begin, other.m_begin);
		ft::swap(this->m_end, other.m_end);
		ft::swap(this->m_comp, other.m_comp);
	}
};
}

#endif

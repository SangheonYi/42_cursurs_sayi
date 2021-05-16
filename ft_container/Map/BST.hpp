#ifndef BST_HPP
# define BST_HPP

# include <iostream>

template <typename T>
struct MapNode
{
    MapNode   *parent;
    MapNode   *left;
    MapNode   *right;
    T        key;
};

template <typename T>
class BST
{
    private:
        MapNode<T>*	_root;
		size_t		_size;

    protected:
        MapNode<T>*	insert_node(MapNode<T>* node, T &key)
		{
			if (node == nullptr)
			{
				node = new MapNode<T>;
				node->key = key;
				node->left = nullptr;
				node->right = nullptr;
				node->parent = nullptr;
				_size++;
			}
			else if (key < node->key)
			{
				node->left = insert_node(node->left, key);
				node->left->parent = node;
			}
			else if (key > node->key)
			{
				node->right = insert_node(node->right, key);
				node->right->parent = node;
			}
			return (node);
		}
		void		print_in_order(MapNode<T> *node)
		{
			if (node == nullptr)
				return ;
			print_in_order(node->left);
			if (node->left)
				std::cout << "(" << node->left->key._key << ",";
			else
				std::cout << "(-1,";
			std::cout << node->key._key << ",";
			if (node->right)
				std::cout << node->right->key._key << ")";
			else
				std::cout << "-1)";
			print_in_order(node->right);
		}
		template <typename K>
		MapNode<T>*	search_node(MapNode<T>* node, K& key)
		{
			if (node == nullptr)
				return (nullptr);
			else if (key == node->key._key)
				return (node);
			else if (key < node->key._key)
				return search_node(node->left, key);
			else if (key > node->key._key)
				return search_node(node->right, key);
			return (nullptr);
		}
		MapNode<T>*	search_node(MapNode<T>* node, T& key)
		{
			if (node == nullptr)
				return (nullptr);
			else if (key == node->key)
				return (node);
			else if (key < node->key)
				return search_node(node->left, key);
			else if (key > node->key)
				return search_node(node->right, key);
			return (nullptr);
		}
		MapNode<T>*	find_min_node(MapNode<T>* node)
		{
			if (node == nullptr)
				return (nullptr);
			else if (node->left == nullptr)
				return (node);
			else
				return (find_min_node(node->left));
		}
		MapNode<T>*	find_end_node(MapNode<T>* node)
		{
			if (node == nullptr)
				return (nullptr);
			else if (node->right == nullptr)
				return (node);
			else
				return find_end_node(node->right);
		}
		MapNode<T>*	successor_node(MapNode<T>* node)
		{
			if (node->right != nullptr)
				return find_min_node(node->right);
			else
			{
				MapNode<T>*	parent = node->parent;
				MapNode<T>*	current = node;

				while ((parent != nullptr) && (current == parent->right))
				{
					current = parent;
					parent = current->parent;
				}
				return (parent);
			}
		}
		MapNode<T>*	predecessor_node(MapNode<T>* node)
		{
			if (node->left != nullptr)
				return (find_end_node(node->left));
			else
			{
				MapNode<T>*	parent = node->parent;
				MapNode<T>*	current = node;

				while ((parent != nullptr) && (current == parent->left))
				{
					current = parent;
					parent = current->parent;
				}
				return (parent);
			}
		}
		MapNode<T>*	remove_node(MapNode<T>* node, T& key)
		{
			if (node == nullptr)
				return (nullptr);
			if (node->key == key)
			{
				MapNode<T>* tmp_node = node;
				if (node->left == nullptr && node->right == nullptr)
				{
					node = nullptr;
					delete tmp_node;
					_size--;
				}
				else if (node->left == nullptr && node->right != nullptr)
				{
					node->right->parent = node->parent;
					node = node->right;
					delete tmp_node;
					_size--;
				}
				else if (node->left != nullptr && node->right == nullptr)
				{
					node->left->parent = node->parent;
					node = node->left;
					delete tmp_node;
					_size--;
				}
				else
				{
					MapNode<T>*	predecessor = predecessor_node(node);
					node->key = predecessor->key;
					node->left = remove_node(node->left, predecessor->key);
				}
			}
			else if (node->key < key)
				node->right = remove_node(node->right, key);
			else
				node->left = remove_node(node->left, key);
			return (node);
		}
		void		delete_node(MapNode<T>* node)
		{
			if (node)
			{
				delete_node(node->left);
				delete node;
				_size--;
				delete_node(node->right);
			}
		}

	public:
		BST() : _root(nullptr), _size(0) {}
		~BST()
		{
			remove_all();
		}
		size_t		get_size()	{ return (_size); }
		void		insert(T key)
		{
			if (_root)
			{
				MapNode<T>*	end_node = get_end();
				MapNode<T>*	max_node = end_node->parent;
				max_node->right = nullptr;
				delete end_node;
			}
			_root = insert_node(_root, key);
			MapNode<T>*	max_node = get_end();
			MapNode<T>*	end_node = new MapNode<T>;
			end_node->left = nullptr;
			end_node->right = nullptr;
			end_node->parent = max_node;
			max_node->right = end_node;
		}
		void		print_in_order()
		{
			std::cout << "[ ";
			print_in_order(_root);
			std::cout << "]" << std::endl;
		}
		template <typename K>
		MapNode<T>*		search(K key)
		{
			MapNode<T>* result = search_node(_root, key);
			return (result);
		}
		MapNode<T>*		search(T key)
		{
			MapNode<T>* result = search_node(_root, key);
			return (result);
		}
		MapNode<T>*	get_min()
		{
			return (find_min_node(_root));
		}
		MapNode<T>*	get_end()
		{
			return (find_end_node(_root));
		}
		MapNode<T>*	successor(T key)
		{
			return (successor_node(search(key)));
		}
		MapNode<T>*	predecessor(T key)
		{
			return (predecessor_node(search(key)));
		}
		void		remove(T key)
		{
			MapNode<T>* tmp = search(key);
			MapNode<T>* end_node = get_end();
			if (tmp->key == end_node->parent->key)
			{
				end_node->parent->right = nullptr;
				end_node->parent = nullptr;
				_root = remove_node(_root, key);
				MapNode<T>* max_node = get_end();
				max_node->right = end_node;
				end_node->parent = max_node;
			}
			else
				_root = remove_node(_root, key);
		}
		void			remove_all()
		{
			if (_root)
			{
				MapNode<T>* end_node = get_end();
				if (end_node->parent)
				{
					end_node->parent->right = nullptr;
					end_node->parent = nullptr;
					delete end_node;
				}
			}
			delete_node(_root);
			_root = nullptr;
		}
		size_t		get_size() const { return (_size); }
};

#endif

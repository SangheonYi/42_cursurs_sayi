#ifndef BST_HPP
# define BST_HPP

# include <iostream>

template <typename T>
struct Bnode
{
    Bnode   *parent;
    Bnode   *left;
    Bnode   *right;
    T        key;
};

template <typename T>
class BST
{
    private:
        Bnode<T>*	_root;
        Bnode<T>*	max_onode;
        Bnode<T>*	min_node;
		size_t		_size;

    protected:
        Bnode<T>*	insert_node(Bnode<T>* node, T &key)
		{
			if (node == nullptr)
			{
				node = new Bnode<T>;
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
		// 중위 표기법
		void		print_in_order(Bnode<T> *node)
		{
			if (node == nullptr)
				return ;
			print_in_order(node->left);
			// std::cout << node->key << " "; 		// 일반 변수 타입 일때
			// std::cout << "(" << node->key._key << "," << node->key._value << ")"; 	// pair 일때!
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
		Bnode<T>*	search_node(Bnode<T>* node, K& key)
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
		Bnode<T>*	search_node(Bnode<T>* node, T& key)
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
		Bnode<T>*	find_min_node(Bnode<T>* node)
		{
			if (node == nullptr)
				return (nullptr);
			else if (node->left == nullptr)
				return (node);
			else
				return (find_min_node(node->left));
		}
		Bnode<T>*	find_max_node(Bnode<T>* node)
		{
			if (node == nullptr)
				return (nullptr);
			else if (node->right == nullptr)
				return (node);
			else
				return find_max_node(node->right);
		}
		// 직후 원소 찾기
		Bnode<T>*	successor_node(Bnode<T>* node)
		{
			// 오른쪽 자식이 있으면 그 서브트리의 최소값이 직후 값!
			if (node->right != nullptr)
				return find_min_node(node->right);
			else
			{
				Bnode<T>*	parent = node->parent;
				Bnode<T>*	current = node;

				while ((parent != nullptr) && (current == parent->right))
				{
					current = parent;
					parent = current->parent;
				}
				return (parent);
			}
		}
		// 직전 원소 찾기
		Bnode<T>*	predecessor_node(Bnode<T>* node)
		{
			if (node->left != nullptr)
				return (find_max_node(node->left));
			else
			{
				Bnode<T>*	parent = node->parent;
				Bnode<T>*	current = node;

				while ((parent != nullptr) && (current == parent->left))
				{
					current = parent;
					parent = current->parent;
				}
				return (parent);
			}
		}
		// 삭제
		Bnode<T>*	remove_node(Bnode<T>* node, T& key)
		{
			if (node == nullptr)
				return (nullptr);

			// 삭제 부분!
			if (node->key == key)
			{
				Bnode<T>* tmp_node = node;		// for delete removed node
				// 자식이 없을 떄
				if (node->left == nullptr && node->right == nullptr)
				{
					node = nullptr;
					delete tmp_node;
					_size--;
				}
				// 오른쪽 자식만 있을 때
				else if (node->left == nullptr && node->right != nullptr)
				{
					node->right->parent = node->parent;
					node = node->right;
					delete tmp_node;
					_size--;
				}
				// 왼쪽 자식만 있을 때
				else if (node->left != nullptr && node->right == nullptr)
				{
					node->left->parent = node->parent;
					node = node->left;
					delete tmp_node;
					_size--;
				}
				// 자식이 둘다 있을 때
				else
				{
					// successor --> predecessor 바꿔주니까 됬음..
					// successor or predecessor
					Bnode<T>*	successor = predecessor_node(node);
					node->key = successor->key;
					node->left = remove_node(node->left, successor->key);
				}
			}
			// 삭제 값이 더 클때 -> 오른쪽
			else if (node->key < key)
				node->right = remove_node(node->right, key);
			// 삭제 값이 더 작을떄 -> 왼쪽
			else
				node->left = remove_node(node->left, key);
			return (node);
		}
		void		delete_node(Bnode<T>* node)
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
			// 최대 값 노드 삭제
			if (_root)
			{
				Bnode<T>*	end_node = get_max();
				Bnode<T>*	max_node = end_node->parent;
				max_node->right = nullptr;
				delete end_node;
			}
			_root = insert_node(_root, key);
			// 최대 값 노드 추가
			Bnode<T>*	max_node = get_max();
			Bnode<T>*	end_node = new Bnode<T>;
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
		Bnode<T>*		search(K key)
		{
			Bnode<T>* result = search_node(_root, key);
			return (result);
		}
		Bnode<T>*		search(T key)
		{
			Bnode<T>* result = search_node(_root, key);
			return (result);
		}
		Bnode<T>*	get_min()
		{
			return (find_min_node(_root));
		}
		Bnode<T>*	get_max()
		{
			return (find_max_node(_root));
		}
		Bnode<T>*	successor(T key)
		{
			return (successor_node(search(key)));
		}
		Bnode<T>*	predecessor(T key)
		{
			return (predecessor_node(search(key)));
		}
		void		remove(T key)
		{
			Bnode<T>* tmp = search(key);
			Bnode<T>* end_node = get_max();
			// 이 경우는 마지막 노드를 삭제 할 때 필요!
			// 최대값 노드 오른쪽 빈 노드가 있기 때문
			if (tmp->key == end_node->parent->key)
			{
				end_node->parent->right = nullptr;
				end_node->parent = nullptr;
				_root = remove_node(_root, key);
				Bnode<T>* max_node = get_max();
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
				Bnode<T>* end_node = get_max();
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

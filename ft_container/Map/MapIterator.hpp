#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP

# include <iostream>
# include "BST.hpp"
# include "Pair.hpp"

namespace ft
{
	template <class Key, class T>
	class MapIterator
	{
		public:
			typedef ft::Pair<Key, T>				value_type;
			typedef ft::Pair<Key, T>&				reference;
			typedef ft::MapNode<ft::Pair<Key, T> >*	pointer;

		protected:
			pointer									_ptr;

		private:
			pointer	find_min_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->left == nullptr)
					return (node);
				else
					return (find_min_node(node->left));
			}
			pointer	find_max_node(pointer node)
			{
				if (node == nullptr)
					return (nullptr);
				else if (node->right == nullptr)
					return (node);
				else
					return find_max_node(node->right);
			}
			pointer	successor_node(pointer node)
			{
				if (node->right != nullptr)
					return find_min_node(node->right);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;

					while ((parent != nullptr) && (current == parent->right))
					{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}
			pointer	predecessor_node(pointer node)
			{
				if (node->left != nullptr)
					return find_min_node(node->left);
				else
				{
					pointer	parent = node->parent;
					pointer	current = node;
					while ((parent != nullptr) && (current == parent->left))
   	 				{
						current = parent;
						parent = current->parent;
					}
					return (parent);
				}
			}

		public:
			MapIterator() : _ptr(nullptr) {}
			MapIterator(pointer ptr) : _ptr(ptr) {}
			MapIterator(const MapIterator &ref) { *this = ref; }
			MapIterator &operator=(const MapIterator &ref) { _ptr = ref._ptr; return (*this); }
			~MapIterator() {}
			value_type  &operator*() { return (_ptr->key); }
			value_type  *operator->() { return (&_ptr->key); }
			MapIterator &operator++() { _ptr = successor_node(_ptr); return (*this); }
			MapIterator operator++(int) { MapIterator tmp(*this); operator++(); return (tmp); }
			MapIterator &operator--() { _ptr = predecessor_node(_ptr); return (*this); }
			MapIterator operator--(int) { MapIterator tmp(*this); operator--(); return (tmp); }
			bool		operator==(const MapIterator<Key, T> &ref)
			{
				return (_ptr->key == ref._ptr->key);
			}
			bool		operator!=(const MapIterator<Key, T> &ref)
			{
				return (_ptr->key != ref._ptr->key);
			}
	};
};  // ft

#endif

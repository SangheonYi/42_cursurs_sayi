#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "BST.hpp"
# include "MapIterator.hpp"
# include "../Iterator.hpp"
# include "Pair.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
		public:
			typedef Key								key_type;
			typedef T								mapped_type;
			typedef ft::Pair<Key, T> 				value_type;
			typedef Compare							key_compare;
			typedef Alloc							allocator_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef value_type*						pointer;
			typedef const value_type*				const_pointer;
			typedef ft::MapIterator<Key, T>			iterator;
			typedef const iterator					const_iterator;
			typedef ReverseIterator<iterator> 		reverse_iterator;
			typedef ReverseIterator<const_iterator> const_reverse_iterator;
			typedef	size_t							size_type;
			class value_compare
			{
				friend class Map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					};
			};

		private:
			typedef	MapNode<value_type>*		Node;

			ft::BST<ft::Pair<Key, T> >			_bst;
			allocator_type						_allocator;
			key_compare							_comp;

		public:
			explicit Map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _comp(comp)  {}
			template <class InputIterator>
			Map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
				: _allocator(alloc), _comp(comp)
			{
				insert(first, last);
			}
			Map (Map& x)
			{
				*this = x;
			}
			~Map() {}
			Map &operator= (Map &ref)
			{
				clear();
				insert(ref.begin(), ref.end());
				return (*this);
			}
			iterator		begin()	{ return (iterator(_bst.get_min())); }
			const_iterator	begin() const { return (const_iterator(_bst.get_min())); }
			iterator		end() { return (iterator(_bst.get_end())); }
			const_iterator	end() const { return (const_iterator(_bst.get_end())); }
			reverse_iterator        rbegin() { return (reverse_iterator(_bst.get_end())); }
			const_reverse_iterator  rbegin() const { return (reverse_iterator(_bst.get_end())); }
			reverse_iterator		rend() { return (reverse_iterator(_bst.get_min())); }
			const_reverse_iterator	rend() const { return (reverse_iterator(_bst.get_min())); }

			bool empty() const { return (_bst.get_size() == 0); }
			size_type size() const { return (_bst.get_size()); }
			size_type max_size() const { return _allocator.max_size(); }
			mapped_type& operator[] (const key_type& k)
			{
				Node tmp = _bst.search(k);
				if (tmp)
					return(tmp->key.second);
				else
				{
					value_type new_pair = ft::Pair<Key, T>(k, mapped_type());
					_bst.insert(new_pair);
					return (_bst.search(k)->key.second);
				}
			}

			ft::Pair<iterator, bool>		insert(const value_type& val)
			{
				Node tmp= _bst.search(val);
				if (tmp)
					return (ft::Pair<iterator, bool>(iterator(tmp), false));
				_bst.insert(val);
				return (ft::Pair<iterator, bool>(iterator(_bst.search(val)), true));
			}
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				Node tmp = _bst.search(val);
				if (tmp)
					return (iterator(tmp));
				_bst.insert(val);
				return (iterator(_bst.search(val)));
			}
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(*first);
					++first;
				}
			}
			void 	   erase(iterator position)
			{
				_bst.remove(*position);
			}
			size_type 	erase(const key_type& k)
			{
				Node tmp = _bst.search(k);
				if (tmp)
				{
					_bst.remove(tmp->key);
					return (1);
				}
				else
					return (0);
			}
			void		erase(iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
			}
			void		swap(Map &x)
			{
				Map<Key, T> tmp;

				tmp.insert(begin(), end());
				clear();
				insert(x.begin(), x.end());
				x.clear();
				x.insert(tmp.begin(), tmp.end());
			}
			void		clear()
			{
				_bst.remove_all();
			}

			key_compare		key_comp() const { return (_comp); }
			value_compare	value_comp() const { return (value_compare(_comp)); }

			iterator		find(const key_type& k)
			{
				if (empty())
					return (end());
				Node tmp = _bst.search(k);
				if (tmp)
					return (iterator(tmp));
				return (end());
			}
			const_iterator	find(const key_type& k) const
			{
				if (empty())
					return (end());
				Node tmp = _bst.search(k);
				if (tmp)
					return (const_iterator(tmp));
				return (end());
			}

			size_type count(const key_type& k)
			{
				if (find(k) != end())
					return (1);
				else
					return (0);
			}
			iterator		lower_bound(const key_type& k)
			{
				iterator it = begin();
				while (it != end())
				{
					if (!_comp(it->first, k))
						break;
					it++;
				}
				return (it);
			}
			const_iterator	lower_bound(const key_type& k) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (!_comp(it->first, k))
						break;
					it++;
				}
				return (it);
			}
			iterator		upper_bound(const key_type& k)
			{
				iterator it = begin();
				while (it != end())
				{
					if (_comp(k, it->first))
						break;
					it++;
				}
				return (it);
			}
			const_iterator	upper_bound(const key_type& k) const
			{
				const_iterator it = begin();
				while (it != end())
				{
					if (_comp(k, it->first))
						break;
					it++;
				}
				return (it);
			}
			ft::Pair<const_iterator, const_iterator>	equal_range(const key_type& __k) const
			{
				/* Node __x = begin().getNode();
				Node __y = end().getNode();
      while (__x)
	{
	  if (key_compare{}(__x->key.first, __k))
	    __x = __x->right;
	  else if (_M_impl._M_key_compare(__k, __x->key.first))
	    __y = __x, __x = _S_left(__x);
	  else
	    {
	      Node __xu(__x);
	      _Base_ptr __yu(__y);
	      __y = __x, __x = _S_left(__x);
	      __xu = _S_right(__xu);
	      return pair<iterator,
			  iterator>(_M_lower_bound(__x, __y, __k),
				    _M_upper_bound(__xu, __yu, __k));
	    }
	}
      return pair<iterator, iterator>(iterator(__y),
				      iterator(__y));*/
				return (ft::Pair<const_iterator, const_iterator>(lower_bound(__k), upper_bound(__k)));
			}

			ft::Pair<iterator, iterator>	equal_range(const key_type& k)
			{
				return (ft::Pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			void		print_all()
			{
				_bst.print_in_order();
			}
	};
}; // ft

#endif

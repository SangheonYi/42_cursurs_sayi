#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
    template<class K, class V>
    struct Pair
    {
        public:
            K       _key;
            V       _value;

            Pair() {}
            Pair(K key, V value) : _key(key), _value(value) {}

            bool operator<(Pair& ref) { return (_key < ref._key); }
            bool operator<=(Pair& ref) { return (_key <=ref._key); }
            bool operator>(Pair& ref) { return (_key > ref._key); }
            bool operator>=(Pair& ref) { return (_key >= ref._key); }
            bool operator==(Pair& ref) { return (_key == ref._key); }
            bool operator!=(Pair& ref) { return (_key != ref._key); }
    };
}; // namespace ft

#endif

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>

namespace ft
{
    template<class K, class V>
    class Pair
    {
        public:
            K       first;
            V       second;

            Pair() {}
            Pair(K key, V value) : first(key), second(value) {}

            bool operator<(Pair& ref) { return (first < ref.first); }
            bool operator<=(Pair& ref) { return (first <=ref.first); }
            bool operator>(Pair& ref) { return (first > ref.first); }
            bool operator>=(Pair& ref) { return (first >= ref.first); }
            bool operator==(Pair& ref) { return (first == ref.first); }
            bool operator!=(Pair& ref) { return (first != ref.first); }
    };
}; // namespace ft

#endif

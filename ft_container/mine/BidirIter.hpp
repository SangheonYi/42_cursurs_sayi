#ifndef BIDIRITER_HPP
# define BIDIRITER_HPP

namespace ft
{
    template <typename T>
    class BidirIter
    {
        public:
            typedef T           value_type;
            typedef T*          pointer;
            typedef T&          reference;

        protected:
            pointer             _ptr;

        public:
            BidirIter() {}
            BidirIter(pointer ptr) : _ptr(ptr) {}
            BidirIter(const BidirIter &ref) { *this = ref; }
            BidirIter &operator=(const BidirIter &ref) { _ptr = ref._ptr; return (*this); }
            ~BidirIter() {}

            pointer getNode() const { return (_ptr); }      // for insert

            bool operator==(const BidirIter &ref) const { return (_ptr == ref._ptr); }           // ==
            bool operator!=(const BidirIter &ref) const { return (_ptr != ref._ptr); }           // !=
            value_type &operator*() { return (_ptr->data); };                                       // *
            value_type operator->() { return (_ptr); }                                              // ->
            BidirIter &operator++() { _ptr = _ptr->next; return (*this); }                       // ++a
            BidirIter operator++(int) { BidirIter tmp(*this); operator++(); return (tmp); }   // a++
            BidirIter &operator--() { _ptr = _ptr->prev; return (*this); }                       // --a
            BidirIter operator--(int) { BidirIter tmp(*this); operator--(); return (tmp); }   // a--
    };
    template <typename T>
    class ReverseBidirIter
    {
         public:
            typedef T           value_type;
            typedef T*          pointer;
            typedef T&          reference;

        protected:
            pointer             _ptr;

        public:
            ReverseBidirIter() {}
            ReverseBidirIter(pointer ptr) : _ptr(--ptr) {}
            ReverseBidirIter(const ReverseBidirIter &ref) { *this = --ref; }
            ReverseBidirIter &operator=(const ReverseBidirIter &ref) { _ptr = --ref._ptr; return (*this); }
            ~ReverseBidirIter() {}

            bool                operator==(const ReverseBidirIter &ref) const { return (_ptr == ref._ptr); }
            bool                operator!=(const ReverseBidirIter &ref) const { return (_ptr != ref._ptr); }
            value_type          &operator*() { return (_ptr->data); };
            value_type          operator->() { return (_ptr); }
            ReverseBidirIter &operator++() { _ptr = _ptr->prev; return (*this); }
            ReverseBidirIter operator++(int) { ReverseBidirIter tmp(*this); operator++(); return (tmp); }
            ReverseBidirIter &operator--() { _ptr = _ptr->next; return (*this); }
            ReverseBidirIter operator--(int) { ReverseBidirIter tmp(*this); operator--(); return (tmp); }

    };
    template <typename T>
    class ConstBidirIter
    {
        public:
            typedef T           value_type;
            typedef T*          pointer;
            typedef T&          reference;

        protected:
            pointer             _ptr;

        public:
            ConstBidirIter() {}
            ConstBidirIter(pointer ptr) : _ptr(ptr) {}
            ConstBidirIter(const ConstBidirIter &ref) { *this = ref; }
            ConstBidirIter &operator=(const ConstBidirIter &ref) { _ptr = ref._ptr; return (*this); }
            ~ConstBidirIter() {}

            pointer getNode() const { return (_ptr); }      // for insert

            bool                operator==(const ConstBidirIter &ref) const { return (_ptr == ref._ptr); }
            bool                operator!=(const ConstBidirIter &ref) const { return (_ptr != ref._ptr); }
            const value_type    &operator*() { return (_ptr->data); };
            const value_type    operator->() { return (_ptr); }
            ConstBidirIter   &operator++() { _ptr = _ptr->next; return (*this); }
            ConstBidirIter   operator++(int) { ConstBidirIter tmp(*this); operator++(); return (tmp); }
            ConstBidirIter   &operator--() { _ptr = _ptr->prev; return (*this); }
            ConstBidirIter   operator--(int) { ConstBidirIter tmp(*this); operator--(); return (tmp); }
    };
    template <typename T>
    class ConstReverseBidirIter
    {
        public:
            typedef T           value_type;
            typedef T*          pointer;
            typedef T&          reference;

        protected:
            pointer             _ptr;

        public:
            ConstReverseBidirIter() {}
            ConstReverseBidirIter(pointer ptr) : _ptr(ptr) {}
            ConstReverseBidirIter(const ConstReverseBidirIter &ref) { *this = ref; }
            ConstReverseBidirIter &operator=(const ConstReverseBidirIter &ref) { _ptr = ref._ptr; return (*this); }
            ~ConstReverseBidirIter() {}

            pointer getNode() const { return (_ptr); }

            bool                operator==(const ConstReverseBidirIter &ref) const { return (_ptr == ref._ptr); }
            bool                operator!=(const ConstReverseBidirIter &ref) const { return (_ptr != ref._ptr); }
            const value_type    &operator*() { return (_ptr->data); };
            const value_type    operator->() { return (_ptr); }
            ConstReverseBidirIter   &operator++() { _ptr = _ptr->prev; return (*this); }
            ConstReverseBidirIter   operator++(int) { ConstReverseBidirIter tmp(*this); operator++(); return (tmp); }
            ConstReverseBidirIter   &operator--() { _ptr = _ptr->next; return (*this); }
            ConstReverseBidirIter   operator--(int) { ConstReverseBidirIter tmp(*this); operator--(); return (tmp); }
    };
};

#endif

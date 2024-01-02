#include <concepts>
#include <iostream>


template<std::integral T>   //std::integral is a standard concept
class Tclass {

};

struct A {};

template<typename T>
concept Nec = requires {
    typename Tclass<T>;
};

int main()
{
    static_assert(Nec<int>); // valid
    static_assert(Nec<A>);  // invalid
}

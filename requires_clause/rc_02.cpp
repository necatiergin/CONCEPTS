#include <concepts>

//std:integral is a standard concept

template<std::integral T>
class Tclass {
};

struct A {};

template <typename T>
concept nec = requires {  //requires expression
    //typename Tclass<T>;
    Tclass<T> {};
};

int main()
{
    static_assert(nec<int>); // valid
    static_assert(nec<A>); // error
}

#include <iostream>
#include <string>

template <typename T>
concept nec = requires(T x)
{
    std::cout << x;
    std::cin >> x;
};

struct A {};

int main()
{
    static_assert(nec<std::string>); //valid
    static_assert(nec<A>); //error
}

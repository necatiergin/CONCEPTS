#include <concepts>
#include <iostream>

template <typename T> 
requires std::integral<T>  //requires clause
T gcd1(T a, T b)
{
    if (b == 0)
        return a;

    return gcd1(b, a % b);
}


template<std::integral T> //constraine template parameter
T gcd2(T a, T b)
{
    if (b == 0)
        return a;

    return gcd2(b, a % b);
}

//abbreviated (constrained) template syntax
std::integral auto gcd3(std::integral auto a, std::integral auto b)
{
    if (b == 0)
        return a;

    return gcd3(b, a % b);
}

//abbreviated (unconstrained) template syntax
auto gcd4(auto a, auto b)
{
    if (b == 0)
        return a;

    return gcd4(b, a % b);
}

int main()
{

    std::cout << "gcd1(40, 28)= " << gcd1(40, 28) << '\n';
    std::cout << "gcd2(40, 28)= " << gcd2(40, 28) << '\n';
    std::cout << "gcd3(40, 28)= " << gcd3(40, 28) << '\n';
    std::cout << "gcd4(40, 28)= " << gcd4(40, 28) << '\n';
}

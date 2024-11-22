#include <concepts>
#include <iostream>

template <typename T>
requires std::integral<T>  //requires clause
T sum1(T a, T b)
{
    return a + b;
}


template<std::integral T> //constrained template parameter
T sum2(T a, T b)
{
    return a + b;
}

//abbreviated (constrained) template syntax
std::integral auto 
sum3(std::integral auto a, std::integral auto b)
{
    return a + b;
}

//abbreviated (unconstrained) template syntax
auto sum4(auto a, auto b)
{
    return a + b;
}

int main()
{

    std::cout << "sum(40, 28)= " << sum1(40, 28) << '\n';
    std::cout << "sum(40, 28)= " << sum2(40, 28) << '\n';
    std::cout << "sum(40, 28)= " << sum3(40, 28) << '\n';
    std::cout << "sum(40, 28)= " << sum4(40, 28) << '\n';
}

// overloading using concepts

#include <type_traits>
#include <concepts>
#include <iostream>

template <typename T>
concept Integral = std::is_integral<T>::value;

template <typename T>
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;

template <typename T>
concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;

void foo(SignedIntegral auto x)
{
    std::cout << "SignedIntegral: " << x << '\n';
}

void foo(UnsignedIntegral auto x)
{
    std::cout << "UnsignedIntegral: " << x << '\n';
}

int main()
{
    foo(-1);
    foo(2u);
    foo(2.4); //invalid
}

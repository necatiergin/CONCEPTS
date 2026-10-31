#include <concepts>
#include <iostream>

template <typename T>
concept Integral = std::integral<T>;

template <typename T>
concept SignedIntegral =
    Integral<T> && std::signed_integral<T>;

template <Integral T>
void foo(T)
{
    std::cout << "Integral\n";
}

template <SignedIntegral T>
void foo(T)
{
    std::cout << "SignedIntegral\n";
}

int main()
{
    foo(10);
}

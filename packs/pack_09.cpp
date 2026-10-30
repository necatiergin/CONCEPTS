#include <concepts>
#include <iostream>

template <typename... Ts>
    requires (std::integral<Ts> && ...)
void foo(Ts... args)
{
    std::cout << sizeof...(args) << '\n';
}

int main()
{
    foo(10, 20, 30);
    foo('A', 10L, 20);

    // foo(10, 3.14); // constraint not satisfied
}

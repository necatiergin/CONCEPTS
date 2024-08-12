#include <concepts>
#include <string>

void foo(const std::convertible_to<std::string> auto& x)
{
    std::string str = x;
    //...
}

void bar(const auto& x)
    requires std::convertible_to<decltype(x), std::string>
{
    std::string str = x;
    //...
}

template <std::convertible_to<std::string> T>
void baz(const T& x)
{
    std::string str = x;
    //...
}

template <typename T>
    requires std::convertible_to<T, std::string>
void func(const T& x) 
{
    std::string str = x;
    //...
}

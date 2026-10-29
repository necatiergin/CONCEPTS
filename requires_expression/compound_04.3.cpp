#include <concepts>

template <typename T>
concept ReturnsInt = requires(T x)
{
    { x.foo() } -> std::same_as<int>;
};

template <typename T>
concept ReturnsDouble = requires(T x)
{
    { x.foo() } -> std::same_as<double>;
};

template <typename T>
concept nec = ReturnsInt<T> || ReturnsDouble<T>;

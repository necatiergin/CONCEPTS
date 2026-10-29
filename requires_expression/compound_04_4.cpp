#include <concepts>

template <typename T>
concept nec = requires(T x)
{
    x.foo();

    requires
    std::same_as<decltype(x.foo()), int> ||
        std::same_as<decltype(x.foo()), double>;
};

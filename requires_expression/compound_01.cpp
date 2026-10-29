template <typename T>
concept nec = requires(T x)
{
    { x.foo() } -> int; // invalid
};

#include <concepts>
template <typename T>
concept erg = requires(T x)
{
    { x.foo() } -> std::same_as<int>; //valid (type-constrained)
};

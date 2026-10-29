#include <concepts>

struct A {
    int& foo();
};

template <typename T>
concept nec = requires(T x)
{
    { x.foo() } -> std::same_as<int>;
};


template <typename T>
concept erg = requires(T x)
{
    { x.foo() } -> std::same_as<int&>;
};


static_assert(!nec<A>);
static_assert(erg<A>);

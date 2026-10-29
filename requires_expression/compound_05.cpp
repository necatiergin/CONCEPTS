#include <concepts>

struct A {
    short foo();
};

template <typename T>
concept nec = requires(T x)
{
    { x.foo() } -> std::same_as<int>;
};

template <typename T>
concept erg = requires(T x)
{
    { x.foo() } -> std::convertible_to<int>;
};

int main()
{
    static_assert(!nec<A>);
    static_assert(erg<A>);
}

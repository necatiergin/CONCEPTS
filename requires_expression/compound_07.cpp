#include <concepts>

struct A {
    int foo();
};

struct B {
    int& foo();
};

struct C {
    int&& foo();
};

template <typename T>
concept ReturnsInt = requires(T x)
{
    { x.foo() } -> std::same_as<int>;
};

template <typename T>
concept ReturnsIntRef = requires(T x)
{
    { x.foo() } -> std::same_as<int&>;
};

template <typename T>
concept ReturnsIntRvalueRef = requires(T x)
{
    { x.foo() } -> std::same_as<int&&>;
};

static_assert(ReturnsInt<A>);
static_assert(ReturnsIntRef<B>);
static_assert(ReturnsIntRvalueRef<C>);

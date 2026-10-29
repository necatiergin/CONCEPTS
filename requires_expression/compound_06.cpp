#include <concepts>

struct A {
    int foo();
};

struct B {
    double foo();
};

struct C {
    int& foo();
};

struct D {
    const int foo();
};

template <typename T>
concept HasIntFoo = requires(T x)
{
    { x.foo() } -> std::same_as<int>;
};

static_assert(HasIntFoo<A>);
static_assert(!HasIntFoo<B>);
static_assert(!HasIntFoo<C>);
static_assert(HasIntFoo<D>);

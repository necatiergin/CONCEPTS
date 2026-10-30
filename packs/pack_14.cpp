#include <concepts>

template <typename... Ts>
concept AllNoThrowCallable = requires(Ts... funcs)
{
    { (funcs(), ...) } noexcept;
};

struct A {
    void operator()() noexcept {}
};

struct B {
    int operator()() noexcept { return 10; }
};

struct C {
    void operator()() {}
};

static_assert(AllNoThrowCallable<A, B>);

static_assert(!AllNoThrowCallable<A, C>);

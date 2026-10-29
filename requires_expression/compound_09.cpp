#include <concepts>
#include <type_traits>

template <typename T, typename U>
concept SameUnqualified =
std::same_as<
    std::remove_cvref_t<T>,
    std::remove_cvref_t<U>>;

template <typename T>
concept nec = requires (T x) {
    { x.foo() }-> SameUnqualified<int>;
};

struct A {
    const int& foo();
};

static_assert(nec<A>);

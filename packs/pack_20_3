#include <type_traits>

template <typename... Ts>
concept AllHaveValueType = requires
{
    typename std::void_t<typename Ts::value_type...>;
};

struct A {
    using value_type = int;
};

struct B {
    using value_type = double;
};

struct C {};

static_assert(AllHaveValueType<A, B>);
static_assert(!AllHaveValueType<A, C>);

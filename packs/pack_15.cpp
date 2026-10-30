#include <concepts>

template <typename... Ts>
concept SumReturnsInt = requires(Ts... args)
{
    { (args + ...) } -> std::same_as<int>;
};

static_assert(SumReturnsInt<int, int, int>);
static_assert(!SumReturnsInt<int, double>);


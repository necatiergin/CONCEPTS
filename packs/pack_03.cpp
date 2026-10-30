#include <concepts>

template <typename... Ts>
concept AnyIntegral = (std::integral<Ts> || ...);

static_assert(AnyIntegral<double, int, float>);
static_assert(AnyIntegral<char, double>);
static_assert(!AnyIntegral<float, double>);
static_assert(!AnyIntegral<>);

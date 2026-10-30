#include <concepts>

template <typename T, typename... Ts>
concept OneOf = (std::same_as<T, Ts> || ...);

static_assert(OneOf<int, char, int, double>);
static_assert(OneOf<double, char, int, double>);
static_assert(!OneOf<float, char, int, double>);
static_assert(!OneOf<int>);

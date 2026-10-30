#include <concepts>

template <typename... Ts>
concept AllIntegral = sizeof...(Ts) > 0 && (std::integral<Ts> && ...);

enum Color { White, Yellow, Red, Brown, Blue, Black };

static_assert(!AllIntegral<>);
static_assert(!AllIntegral<int, double, int>);
static_assert(!AllIntegral<int, char, Color>);
static_assert(AllIntegral<int, char, long>);


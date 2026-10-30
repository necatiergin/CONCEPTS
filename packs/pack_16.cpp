#include <concepts>

template <typename... Ts>
concept AllIntegral = requires
{
    requires (std::integral<Ts> && ...);
};

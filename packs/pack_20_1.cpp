#include <concepts>

template <typename... Ts>
concept AllHaveValueType = requires
{
    typename Ts::value_type...; // invalid
};

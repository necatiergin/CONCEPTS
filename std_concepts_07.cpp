#include <concepts>

template <typename T, typename... U>
concept IsAnyOf = (std::same_as<T, U> || ...);

template <typename T>
concept IsSupportedType = IsAnyOf<T, std::int32_t, std::int64_t, float, double>;

static_assert(IsSupportedType<float >);

#include <concepts>

template <typename T, typename... U>
concept AnyOfTypes = std::disjunction_v<std::is_same<T, U>...>;

template <typename T>
concept SupportedType = AnyOfTypes<T, std::int32_t, std::int64_t, float, double>;

static_assert(SupportedType<float >); //holds
static_assert(SupportedType<char>); //fails

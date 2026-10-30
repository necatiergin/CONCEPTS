#include <concepts>
#include <string>

template <typename Target, typename... Ts>
concept AllConvertibleTo =
(std::convertible_to<Ts, Target> && ...);

static_assert(AllConvertibleTo<double, int, float, char>);

static_assert(!AllConvertibleTo<int, int, std::string>);

#include <concepts>
#include <vector>
#include <utility>

template <typename T, typename... Args>
    requires (std::convertible_to<Args, T> && ...)
std::vector<T> make_vector(Args&&... args)
{
    return { std::forward<Args>(args)... };
}

auto v1 = make_vector<double>(1, 2.5, 3.0f);
auto v2 = make_vector<int>(10, 20, 30);

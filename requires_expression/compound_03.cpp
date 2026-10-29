#include <concepts>
#include <cstddef>

template <typename T>
concept ContainerLike = requires(T x, const T cx)
{
    { x.begin() };
    { x.end() };

    { cx.size() } -> std::convertible_to<std::size_t>;

    { cx.empty() } -> std::convertible_to<bool>;

    { x.clear() } -> std::same_as<void>;
};

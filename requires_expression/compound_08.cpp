#include <concepts>
#include <cstddef>

template <typename T>
concept Indexable = requires(T x, std::size_t i)
{
    { x[i] } -> std::same_as<typename T::value_type&>;
};

#include <concepts>
#include <functional>
#include <utility>

template <typename F, typename... Args>
concept InvocableReturningInt =
    requires(F && f, Args&&... args)
{
    {
        std::invoke(
            std::forward<F>(f),
            std::forward<Args>(args)...)
    } -> std::same_as<int>;
};

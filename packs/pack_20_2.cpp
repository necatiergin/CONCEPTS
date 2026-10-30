#include <vector>
#include <list>
#include <concepts>

template <typename T>
concept HasValueType = requires
{
    typename T::value_type;
};

template <typename... Ts>
concept AllHaveValueType = (HasValueType<Ts> && ...);

static_assert(AllHaveValueType<
    std::vector<int>,
    std::list<double>>);

static_assert(!AllHaveValueType<
    std::vector<int>,
    int>);

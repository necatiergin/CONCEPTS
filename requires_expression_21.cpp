#include <concepts>
#include <ranges>

template<typename T, typename U>
concept Con = requires {
	typename T::value_type; // type member value_type required for T
	typename std::ranges::iterator_t<T>; // iterator type required for T
	typename std::common_type_t<T, U>; // T and U have to have a common type
};

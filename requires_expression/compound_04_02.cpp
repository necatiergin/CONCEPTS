#include <concepts>

template <typename T>
concept IntOrDouble = std::same_as<T, int> || std::same_as<T, double>;

template <typename T>
concept nec = requires(T x)
{
	{ x.foo() } -> IntOrDouble; //valid
};


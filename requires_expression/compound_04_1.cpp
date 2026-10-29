#include <concepts>

concept nec = requires (T x) {
	{ x.foo() } -> std::same_as<int> || std::same_as<double>; // invalid 
};

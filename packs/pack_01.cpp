#include <concepts>

template <typename... Ts>
concept AllIntegral = (std::integral<Ts> && ...);

template <AllIntegral ...Ts>
class Myclass {
	//...
};

Myclass<int, long, short> x1; //valid
Myclass<int, double, char> x2; // invalid

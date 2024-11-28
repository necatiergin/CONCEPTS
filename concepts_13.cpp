#include <type_traits>
#include <concepts>

consteval int sum(int x, int y)
{
	return x + y;
}

template <std::integral auto x, std::integral auto y>
requires (sum(x, y) > 10)
class Myclass {

};

int main()
{
	Myclass<3, 9> m1; // valid
	//Myclass<5, 2> m2; // invalid
	//...
}

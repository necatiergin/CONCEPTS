#include <concepts>
#include <type_traits>
#include <iostream>

template <typename T>
requires std::floating_point<T>
constexpr T pi = T(3.1415926525897932384L);

int main()
{
	//std::cout << pi<int> << '\n';
	std::cout << pi<float> << '\n';
}

#include <type_traits>
#include <cmath>
#include <iostream>

template <typename T>
auto get_remainder(T a, T b) 
-> std::enable_if_t<std::is_integral_v<T>, decltype(a % b)>
{
	return a % b;
}

template <typename T>
auto get_remainder(T a, T b)
-> std::enable_if_t<std::is_floating_point_v<T>, decltype(std::fmod(a, b))>
{
	return std::fmod(a, b);
}


int main()
{
	int x{ 5 }, y{ 3 };
	double d1{ 3.98 }, d2{ 1.465 };

	std::cout << get_remainder(x, y) << '\n';
	std::cout << get_remainder(d1, d2) << '\n';
}

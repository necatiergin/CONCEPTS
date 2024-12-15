#include <type_traits>
#include <iostream>

template <typename T, typename U>
concept Comparable = requires (T t, U u) {
	t < u;
	u < t;
	t == u;
	u == t;
};

template <typename T>
concept Pointer = std::is_pointer_v<T>;

auto get_max(auto a, auto b) 
{
	return b < a ? a : b; 
}

auto get_max(Pointer auto x, Pointer auto y) 
requires Comparable<decltype(*x), decltype(*y)>
{
	return get_max(*x, *y);
}

int main()
{
	int x = 435;
	int y = 142;
	int* px = &x;
	int* py = &y;

	auto max = get_max(px, py);
	std::cout << "max = " << max << '\n';
}

#include <concepts>

template <typename T>
requires std::integral<T> && std::copyable<T>
constexpr int foo(T)
{
	return 1;
}

template <typename T>
requires std::integral<T> 
constexpr int foo(T)
{
	return 2;
}

int main()
{
	constexpr auto val = foo(42);	 //val ==> 1
}


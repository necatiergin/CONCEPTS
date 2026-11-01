#include <concepts>
#include <iostream>

template <std::integral T>
struct Nec {
	Nec()
	{
		std::cout << "primary template\n";
	}
	T mx{};
	//...
};

template <std::integral T>
requires (sizeof(T) == 4)
struct Nec<T> {
	Nec()
	{
		std::cout << "constrained partial spec.\n";
	}
};

int main()
{
	Nec<long long> x;
	Nec<unsigned> y;
}

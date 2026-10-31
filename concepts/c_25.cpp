#include <concepts>
#include <iostream>

template <typename T>
struct Myclass {
	Myclass()
	{
		std::cout << "primary template\n";
	}
};

template <typename T>
requires std::integral<T>
struct Myclass<T> {
	Myclass()
	{
		std::cout << "constrained specialization\n";
	}
};

int main()
{
	Myclass<int> x;
	Myclass<double> y;
}

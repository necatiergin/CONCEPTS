#include <concepts>
#include <iostream>

template <typename T>
class Myclass {
public:

	void foo() requires std::integral<T>
	{
		std::cout << "integral\n";
	}

	void foo() requires std::floating_point<T>
	{
	}
};

int main()
{
	Myclass<int> x;
	Myclass<double> y;

	x.foo();
	y.foo();
}

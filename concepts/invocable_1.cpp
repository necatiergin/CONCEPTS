#include <concepts>

void func(std::invocable<int> auto f, int x)
{
	f(x);
}

int main()
{
	func([](int x) {return x * x;}, 20);
}

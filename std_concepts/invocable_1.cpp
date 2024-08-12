#include <concepts>
#include <string>

void func(std::invocable<int> auto f, int x)
{
	f(x);
}

int main()
{
	func([](int x) {return x * x; }, 20);
	//func([](std::string x) {return x + ".txt"; }, 20);
}

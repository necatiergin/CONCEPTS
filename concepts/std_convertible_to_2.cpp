#include <concepts>
#include <iostream>
#include <string>
#include <memory>


template <std::convertible_to<bool> T>
void foo(T x)
{
	std::cout << static_cast<bool>(bar) << '\n';
}

int main()
{
	boolalpha(std::cout);
	int x{243};

	foo(x);
	foo(&x);
	//foo(nullptr);
	foo("murat");
	//foo(std::string{"murat"});
	//foo(std::make_unique<int>(234));
}

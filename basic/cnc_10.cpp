#include <concepts>
#include <string>

template <typename T, std::convertible_to<T> auto val>
class Myclass {
	//...
};

struct A {
	operator std::string()const;
};

struct B {};

char name[] = "necati";

int main()
{
	Myclass<std::string, name> m1;
	Myclass<std::string, A{}> m2;
	//Myclass<std::string, B{}> m3;	  // error
}



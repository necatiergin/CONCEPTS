#include <concepts>

int foo();
double bar();
float baz();

int main(void)
{
	//std::floating_point auto f1 = foo();    //error
	std::floating_point auto f2 = bar();    //valid
	std::floating_point auto f3 = baz();    //valid
}

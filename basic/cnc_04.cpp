#include <type_traits>

template <typename T>
concept Pointer = std::is_pointer_v<T>;

template <typename T>
requires Pointer<T> 
class Foo {

};

template <Pointer T>
class Bar {

};

int main()
{
	Foo<int *> x1;
	Bar<double *> x2;
	Foo<int> x3; //error
	Bar<double> x4; //error 
}



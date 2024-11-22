#include <type_traits>

template <typename T>
concept Pointer = std::is_pointer_v<T>;

template <typename T, typename U>
requires Pointer<T> && (!Pointer<U>) 
class Foo {

};

int main()
{
	Foo<int*, double> x1;
	Foo<int, double> x2; //error
	Foo<int* , double*> x3; //error
}

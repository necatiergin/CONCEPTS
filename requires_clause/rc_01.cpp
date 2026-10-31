#include <concepts>
#include <vector>

template<typename T>
requires (sizeof(T) > 2) // ad-hoc Boolean expression
&& requires { typename T::value_type; } // requires expression
&& std::input_iterator<T> // concept
void foo(T x) {
	
}

// to satisfy the constaints
// a) sizeof(T) should be greater than 2
// b) type T should have a nested type named value_type
// c) type T should satisfy the standard concept  std::input_iterator

int main()
{
	std::vector<int> ivec(10);
	foo(ivec.begin());
}

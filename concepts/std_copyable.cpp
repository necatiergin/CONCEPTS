#include <concepts>


template <std::copyable T>
class Myclass {
	//...
};


struct A { };

struct B {
	B() = default;
	B(const B&) = default;
	B& operator=(const B&) = default;
};

struct C {
	C() = default;
	C(const B&) = delete;
	C& operator=(const C&) = delete;
};

struct D {
	D() = default;
	D(const D&) = default;
	D& operator=(const D&) = default;
	D(D&&) = delete;
	D& operator=(D&&) = delete;
};

int main()
{
	Myclass<int> m1;
	Myclass<A> m2;
	Myclass<B> m3;
	//Myclass<C> m4;
	//Myclass<D> m5;
}

// quoted from the book c++20 by jossutis

#include <bit>

template<auto Val>
concept PowerOf2 = std::has_single_bit(static_cast<unsigned>(Val));

template<typename T, auto Val>
requires PowerOf2<Val>
class Memory {
	//...
};

int main()
{
	Memory<int, 8> m1; // OK
	//Memory<int, 9> m2; // ERROR
	Memory<int, 32> m3; // OK
	Memory<int, true> m4; // OK
	//...
}

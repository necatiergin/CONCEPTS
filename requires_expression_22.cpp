#include <concepts>

template<std::floating_point T>
class Nec {

};

template<typename T>
concept Con = requires {
	typename Nec<T>; // instantiation of Nec have to be valid
};

int main()
{
	static_assert(Con<float>); //holds
	static_assert(Con<int>); //fails
}

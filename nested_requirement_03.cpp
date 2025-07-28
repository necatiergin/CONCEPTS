#include <concepts>

template<typename T>
concept Con = requires {
	requires std::floating_point<T>; // nested requirement
};

int main()
{
	static_assert(Con<float>); //holds
	static_assert(Con<int>); //fails
	static_assert(Con<int*>); //fails
}

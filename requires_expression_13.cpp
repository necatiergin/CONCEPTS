#include <concepts>

template<typename T>
concept Con = requires {
	std::floating_point<T>; // must be wrong
};

int main()
{
	static_assert(Con<float>); //holds
	static_assert(Con<int>); //holds
	static_assert(Con<int*>); //holds
}

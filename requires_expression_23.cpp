#include <utility>

template<typename T>
concept C1 = requires {
	typename std::hash<T>; // must be wrong
};

template<typename T>
concept C2 = requires {
	std::hash<T>{}; // simple requirement
};

struct Myclass{};

int main()
{
	static_assert(C1<int>); //holds;
	static_assert(C1<Myclass>); //holds;
	static_assert(C2<int>); //holds;
	static_assert(C2<Myclass>); //fails;
}

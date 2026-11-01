#include <concepts>

template <typename T>
concept Cn = requires {
	//requires std::is_integral_v<T>;
	//requires std::integral<T>;
	//std::is_integral<T>{};
	//typename std::enable_if_t<std::is_integral_v<T>>;
};

int main()
{
	static_assert(Cn<int>);
	static_assert(Cn<double>);
}

#include <iostream>
#include <ranges>

template<typename T>
class ValOrColl {
	T value;
public:
	ValOrColl(const T& val) : value{ val } {}
	ValOrColl(T&& val) : value{ std::move(val) } { }
	void print() const 
	{
		std::cout << value << '\n';
	}

	void print() const requires std::ranges::range<T> 
	{
		for (const auto& elem : value) {
			std::cout << elem << ' ';
		}
		std::cout << '\n';
	}
	//...
};

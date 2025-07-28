#include <iostream>
#include <ranges>
#include <vector>

template<typename T>
class ValOrColl {
	T value;
public:
	ValOrColl(const T& val) : value{ val } {}
	ValOrColl(T&& val) : value{ std::move(val) } {}
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

int main()
{
	std::vector<int> ivec(5);
	ValOrColl x(ivec);

	x.print();

	ValOrColl<int> y(10);
	y.print();
}

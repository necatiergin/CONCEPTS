#include <set>
#include <type_traits>
#include <string>


template <typename T>
requires std::integral<T>
using gset = std::set<T, std::greater<T>>;

int main()
{
	gset<int> x;
	//gset<std::string> y;
}


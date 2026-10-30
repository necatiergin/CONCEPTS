#include <concepts>
#include <string>
#include <iostream>

template <typename T, typename... Ts>
concept OneOf = (std::same_as<T, Ts> || ...);

static_assert(OneOf<int, char, int, double>);
static_assert(OneOf<double, char, int, double>);
static_assert(!OneOf<float, char, int, double>);
static_assert(!OneOf<int>);

template <typename T>
    requires OneOf<T, int, double, std::string>
void print(const T& value)
{
    std::cout << value << '\n';
}

int main()
{
    print(10);
    print(3.14);
    print(std::string{ "hello" });

    print('A'); // constraint not satisfied
}

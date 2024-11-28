#include <type_traits>

template <typename T>
concept intlike = std::is_integral_v<T> || std::is_convertible_v<T, int>;

template <intlike T>
void func(T x);

struct Nec {
public:
	operator int()const;
};

struct Erg { };

int main(void)
{
	func(12); //OK
	func(Nec{}); //OK
	//func(Erg{}); //error
}

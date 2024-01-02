#include <concepts>

template <typename T>
concept ref_or_ptr = std::is_pointer_v<T> || std::is_reference_v<T>;

template <ref_or_ptr T>
void func(T x);

int main()
{

	int x{};

	//func(x);  //error
	//func<int>(x);  //error
	func(&x);
	func<int&>(x);
}

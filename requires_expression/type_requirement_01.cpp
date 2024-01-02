#include <vector>

class Nec{};

template<typename C>
concept has_value_type = requires {
	typename C::value_type;
};

void foo(const has_value_type auto&);


int main()
{
	std::vector vec {4 ,6, 8 ,1, 3};

	foo(vec); //valid
	//foo(Nec{});
}



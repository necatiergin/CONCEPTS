#include <utility>

template <typename Container>
concept ConTypes = requires {
	typename Container::value_type::first_type;
	typename Container::value_type::second_type;
};

struct A {
	using value_type = int;
	//...
};

struct B {
	using value_type = std::pair<int, int>;
	//...
};


template <ConTypes>
class Nec {

};


int main()
{
	//Nec<A> n1; //error
	Nec<B> n2;  //valid
}

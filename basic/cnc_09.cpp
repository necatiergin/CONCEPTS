#include <concepts>

template <std::floating_point auto DVAL>
class Myclass {
	//...
};

int main()
{
	Myclass<3.4> m1; //valid
	Myclass<1.7F> m2; //valid
	Myclass<9.7> m3; //valid
	//Myclass<5> m4; //error
}

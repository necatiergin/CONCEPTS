template<typename T>
concept Con = requires(T x, T y) {
	x + y;   //simple requirement
	x - y;   //simple requirement
};

void func(Con auto);

#include <complex>
#include <string>

int main()
{
	func(12); //valid
	func(1.2); //valid
	func(std::complex{ 1.2, 4.5 }); //valid
	//func(std::string{"neco"}); //invalid
}




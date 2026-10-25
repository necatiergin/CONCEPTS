#include <iostream>

template<typename Container>
concept ElemsWritable = requires(typename Container::value_type elem) {
	std::cout << elem; 	//simple requirement
};


template <ElemsWritable>
class Myclass {
	//...
};


#include <vector>
#include <string>

int main()
{
	//Myclass<int> m1; //invalid
	Myclass<std::vector<int>> m2; //valid
	Myclass<std::vector<std::string>> m3; //valid
	//Myclass<std::vector<std::pair<int, int>> m4; //invalid
}

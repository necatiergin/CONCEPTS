#include <concepts>
#include <string>

void foo(std::totally_ordered auto x);


struct Nec {};
struct Erg {
	auto operator<=>(const Erg& rhs) const = default;
};

struct Bar {
	bool operator==(const Bar &)const;
};

int main()
{
	foo(1);
	foo(std::string{"remzi"});
	//foo(Nec{}); //invalid
	foo(Erg{}); 
	//foo(Bar{}); 
}

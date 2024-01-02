#include <iostream>


template <typename T>
concept nec = requires(T x)
{
    std::cout << x;
    std::cin >> x;
};

struct A {};

class B {
public:
    friend std::ostream& operator<<(std::ostream&, const B&);
    friend std::istream& operator>>(std::istream&, B&);
};

int main()
{
    //static_assert(nec<A>); //invalid
    static_assert(nec<B>); 
}

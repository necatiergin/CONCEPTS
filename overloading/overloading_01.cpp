#include <concepts>
#include <iostream>

void foo(auto x) 
{
    std::cout << "foo(auto)     : " << x << '\n';
}

void foo(std::integral auto x) 
{
    std::cout << "foo(Integral) : " << x << '\n';
}

void foo(float x) 
{
    std::cout << "foo(float)    : " << x << '\n';
}

int main() 
{
    foo(1.5);
    foo(23);
    foo(1.4f);
}

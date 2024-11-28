//concept HasValueType below uses a requires expression.
// the requires expression has a type requirement.
// type C should have a nested type named value_type

template<typename C>
concept HasValueType = requires {
    typename C::value_type;
};

struct A
{
    using value_type = int;
};

struct B {};

template <typename T>
requires HasValueType<T>
class Myclass {

};

void foo(HasValueType auto);

template<HasValueType T>
void bar(T);

#include <vector>

int main()
{
    //Myclass<int> m1; // error

    Myclass<A> m2; // ok
    foo(A{}); //ok
    //foo(B{}); // error
    bar(A{});
    Myclass<std::vector<int>> m3;
    //...
}

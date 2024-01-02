template<typename C>
concept necval = requires {
    typename C::value_type;
};

struct A
{
    using value_type = int;
};

struct B {};

template <typename T>
requires necval<T>
class Myclass {

};

void func(necval auto);

int main()
{
    //Myclass<int> x; // error

    Myclass<A> y; // ok
    func(A{}); //ok
    //func(B{}); // error
}

template <typename T>
concept nec = requires(T a, T b)  //requires expression
{
    a + b;
};

int main()
{
    static_assert(nec<int>); // valid
    static_assert(nec<int*>); // error
}

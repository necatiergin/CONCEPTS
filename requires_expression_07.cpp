template <typename T>
concept nec = requires(T a, T b)
{
    a - b;
};

int main()
{
    static_assert(nec<int*>); // valid
};

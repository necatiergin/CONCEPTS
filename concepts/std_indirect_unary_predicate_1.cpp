#include <iostream>
#include <iterator>
#include <vector>

template <typename F, typename Iter>
void bar(F fn, Iter iter)
requires std::indirect_unary_predicate<F, Iter> 
{
    std::cout << fn(*iter) << '\n';
}

int main()
{
    const auto pred = [](int x) {return x % 5 == 0;};
    std::vector ivec{4, 50, 12, 20, 35, 7, 9, 40};

    boolalpha(std::cout);

    for (auto iter = ivec.begin(); iter != ivec.end(); ++iter) {
        bar(pred, iter);
    }
}

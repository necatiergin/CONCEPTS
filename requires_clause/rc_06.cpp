#include <memory>
#include <optional>

template <typename T>
concept nec = requires(T p)
{
    p == nullptr; //unevaluated expression.
    //ifadenın kendisi geçerli olmalı.
    //ifadenin değerinin true ya da false olması önemsiz
};

int main() {

    static_assert(nec<int*>); // valid
    static_assert(nec<std::unique_ptr<int>>);  //valid

    static_assert(nec<std::nullptr_t>);  // valid
    static_assert(nec<std::optional<int*>>);  // valid
    static_assert(nec<std::optional<int>>);  //invalid
}

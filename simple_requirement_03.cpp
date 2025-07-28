#include <memory>
#include <optional>
#include <string>

template <typename T>
concept nec = requires(T p)
{
    p == nullptr; //unevaluated expression.
    //expression must be valid
    // the result of expression may be true or false
};

int main() {

    static_assert(nec<int*>); // valid
    static_assert(nec<std::unique_ptr<int>>);  //valid

    static_assert(nec<std::nullptr_t>);  // valid
    static_assert(nec<std::optional<int*>>);  // valid
    static_assert(nec<std::optional<int>>);  //invalid
    static_assert(nec<std::string>);  //invalid
}

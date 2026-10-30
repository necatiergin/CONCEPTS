#include <concepts>

template <std::integral... Ts>
void foo(Ts... args)
{}

void bar(std::integral auto... args)
{}

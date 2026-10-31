#include <concepts>

template <typename F>
concept invoke_integral = requires (F f) {
    { f() } -> std::integral; //compound requirement
};

template <invoke_integral F>
void foo(F f) {};

int main() 
{
    foo([]() { return 42; }); // valid
    foo([]() { return 4.3; }); // invalid return type is notintegral
    foo(42); // 42() is not valid
}

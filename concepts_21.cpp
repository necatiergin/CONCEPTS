template <typename T>
concept has_x = requires (T t) {
    t.foo();
};

template <typename T>
concept coord = has_x<T> && requires (T t) {
    t.bar();
};

void func(has_x auto) {}
void func(coord auto) {}

struct A {
    int foo();
};

struct B {
    int foo();
    int bar();
};

int main() {
    func(A{});  //valid
    func(B{}); // valid
}

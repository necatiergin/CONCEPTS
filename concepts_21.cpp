template <typename T>
concept has_foo = requires (T t) {
    t.foo();
};

template <typename T>
concept coord = has_foo<T> && requires (T t) {
    t.bar();
};

void func(has_foo auto) {}
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

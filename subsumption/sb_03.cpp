template <typename T>
concept Large = (sizeof(T) > 4);

template <typename T>
concept VeryLarge = (sizeof(T) > 8);

template <Large T>
void foo(T);

template <VeryLarge T>
void foo(T);

struct Nec {
	char buf[16]{};
};

int main()
{
	foo(Nec{});	 // error - ambiguos call
}

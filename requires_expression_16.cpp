template<typename T, typename P>
concept Con = requires(T tval, P p) {
	*p || *p < tval || p == nullptr;
};


template <typename T, typename P>
requires Con<T, P>
class Myclass {
	//...
};

int main()
{
	Myclass<int, int*> m1;
	Myclass<int, int> m2;	// invalid
	//...
}

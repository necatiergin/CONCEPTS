constexpr bool isprime(int x)
{
	if (x < 2) return false;
	if (x == 2 || x == 3 || x == 5)	return true;
	if (!(x % 2 && x % 3 && x % 5))	return false;
	for (int i = 7; i * i <= x; i += 2)
		if (x % i == 0) return false;

	return true;
}

template <int N>
concept Prime = isprime(N);

static_assert(Prime<17>); // holds
static_assert(Prime<39>); //fails

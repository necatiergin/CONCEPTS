template <auto N>
concept SingleSetBit = static_cast<bool>(N && !(N & (N - 1)));

int main()
{
	//static_assert(SingleSetBit<0>); //fails
	static_assert(SingleSetBit<1>); // holds
	static_assert(SingleSetBit<16>); //holds
	//static_assert(SingleSetBit<17>); //fails
}

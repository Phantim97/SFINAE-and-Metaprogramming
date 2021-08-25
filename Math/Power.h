//Compile time exponentiation
template <int b, int e>
struct Power
{
	static const int value = b * Power<b, e - 1>::val;
};

template<int b>
struct Power<b, 0>
{
	static const int value = 1;
};

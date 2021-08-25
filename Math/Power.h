//Compile time exponentiation
template <int b, int e>
struct Power
{
	static const int val = b * Power<b, e - 1>::val;
};

template<int b>
struct Power<b, 0>
{
	static const int val = 1;
};

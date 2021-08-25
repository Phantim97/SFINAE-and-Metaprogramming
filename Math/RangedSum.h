template<int low, int high>
struct RangedSum
{
public:
	static const int sum = static_cast<int>((((high - low) + 1) / 2.0) * (high + low));
};

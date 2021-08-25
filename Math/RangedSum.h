template<int l, int h>
struct RangedSum
{
public:
	static constexpr int sum = static_cast<int>((((h - l) + 1) / 2.0) * (h + l));
};

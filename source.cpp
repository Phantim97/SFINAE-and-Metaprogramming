#include <iostream>
#include "MetaMath/RangedSum.h"
#include "MetaMath/Power.h"

void power_and_ranged_sum()
{
	std::cout << Power<2, 5>::value << '\n';;
	std::cout << RangedSum<55, 60>::sum << '\n';;
}

int main()
{
	power_and_ranged_sum();

	return 0;
}
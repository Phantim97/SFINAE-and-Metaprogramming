#include <iostream>
#include "MetaMath/RangedSum.h"
#include "MetaMath/Power.h"
#include "MetaMath/MetaCalculator.h"

void power_and_ranged_sum()
{
	std::cout << Power<2, 5>::value << '\n';;
	std::cout << RangedSum<55, 60>::sum << '\n';;
}

void calc_test()
{
	//SFINAE calculator
	MetaCalculator c(1.0); //Template implicitly defined via constructor
	c.toggle_result_printing();
	c + 5;
	c ^ 2;
	//c % 2; //Since this was initialized to double it will fail
	MetaCalculator c2(2);
	c2 + 2;
	c2 + 8;
	c2 + 2.0; //This step casts c2 to a double which means that the next line will cause a compile error
	//c % 2;
	std::cout << "Current Value: " << c2 << '\n';
}

int main()
{
	power_and_ranged_sum();

	calc_test();

	return 0;
}
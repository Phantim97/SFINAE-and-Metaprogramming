#include <iostream>
#include "MetaMath/RangedSum.h"
#include "MetaMath/Power.h"
#include "MetaMath/MetaCalculator.h"
#include "MetaMath/Fraction.h"
#include "ScopedTimer/ScopedTimer.h"

void power_and_ranged_sum()
{
	std::cout << Power<2, 5>::value << '\n';
	std::cout << RangedSum<55, 60>::sum << '\n';
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

void fraction_sample()
{
	//SFINAE Fraction class
	Fraction f1(1, 4);
	const short num = 2;
	const short denom = 3;
	Fraction f2(num, denom);
	Fraction f3(2, 5);
	Fraction f4(2, denom);
	Fraction f5(2, denom);
	Fraction f6 = f1 + f3;
	std::cout << f1 + f2 << '\n';
	std::cout << f1 / f2 << '\n';
	std::cout << f4 * f3 << '\n';
	std::cout << f3.decimal_representation() << '\n';
}

//Scoped Timer functions
void f1()
{
	ScopedTimer<std::chrono::milliseconds>();

	long double sum = 0.0;

	for (int i = 0; i < 10000000; i++)
	{
		sum += i * 65.463;
	}
}

void f2()
{
	ScopedTimer<std::chrono::nanoseconds>();

	long double sum = 0.0;

	for (int i = 0; i < 10000000; i++)
	{
		sum += i * 65.463;
	}
}

void timer_demo()
{
	f1();
	f2();
}

int main()
{
	power_and_ranged_sum();

	calc_test();

	fraction_sample();

	timer_demo();
	return 0;
}

#pragma once
#include <concepts>
#include <string>
#include <type_traits>

//Concepts overall are just a cleaner way of making SFINAE a thing without
//having to do such extensive type validation as numeric_types.h
//but pre C++20 other mechanisms such as std::enable_if and others
//will be required instead

//Constraint for integral types only
template <typename T>
concept integral = std::is_integral_v<T>;

//Restricts operation solely to integral types
template <typename T>
int modulus_ret(T a, T b) requires integral<T>
{
	return a % b;
}
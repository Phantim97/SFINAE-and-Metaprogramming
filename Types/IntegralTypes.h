#pragma once
//SFINAE approach 

//From Thomas Kim's: https://www.youtube.com/watch?v=TEmUnxYTTQs&list=PL1_C6uWTeBDF4oRLtCP_NqFtzP1DrQC6f

template<typename T>
struct st_integer
{
	static const bool val = false;
};

//Full specialization for template class
template<>
struct st_integer<int>
{
	static const bool val = true;
	using type = int;
};

template<>
struct st_integer<short>
{
	static const bool val = true;
	using type = short;
};

template<>
struct st_integer<long>
{
	static const bool val = true;
	using type = long;
};

template<>
struct st_integer<long long>
{
	static const bool val = true;
	using type = long long;
};

//Unsigned

//Full specialization for template class
template<>
struct st_integer<unsigned int>
{
	static const bool val = true;
	using type = unsigned int;
};

template<>
struct st_integer<unsigned short>
{
	static const bool val = true;
	using type = unsigned short;
};

template<>
struct st_integer<unsigned long>
{
	static const bool val = true;
	using type = unsigned long;
};

template<>
struct st_integer<unsigned long long>
{
	static const bool val = true;
	using type = unsigned long long;
};

//value template using constexpr keyword
template<typename T>
constexpr bool is_integer = st_integer<T>::val; // compile time resolution

//using template - type alias
template<typename T>
using integer_t = typename st_integer<T>::type;

//Identical type check
//Primary Template Class
template<typename T1, typename T2>
struct st_same_type
{
	static const bool value = false;
};

//Partial Specialization
template<typename T> //Partial means we still need template parameter
struct st_same_type<T, T>
{
	static const bool value = true;
	using type = T;
};

//value template
template<typename T1, typename T2>
constexpr bool is_same_v = st_same_type<T1, T2>::value;

//using template - type alias
template<typename T1, typename T2>
using same_t = typename st_same_type<T1, T2>::type;

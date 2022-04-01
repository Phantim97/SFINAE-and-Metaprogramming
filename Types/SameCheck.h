#pragma once
//value template
template<typename T1, typename T2>
constexpr bool is_same_v = st_same_type<T1, T2>::value;

//using template - type alias
template<typename T1, typename T2>
using same_t = typename st_same_type<T1, T2>::type;

#pragma once
template<int n>
struct TilingCombinations
{
    static constexpr int value = TilingCombinations<n - 1>::value + TilingCombinations<n - 2>::value;
};

template<>
struct TilingCombinations<2>
{
    static constexpr int value = 2;
};

template<>
struct TilingCombinations<1>
{
    static constexpr int value = 1;
};
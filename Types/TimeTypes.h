#include <chrono>

template <typename T>
struct st_time
{
	static const bool val = false;
};

template<>
struct st_time<std::chrono::nanoseconds>
{
	static const bool val = true;
	using type = std::chrono::nanoseconds;
};

template<>
struct st_time<std::chrono::milliseconds>
{
	static const bool val = true;
	using type = std::chrono::milliseconds;
};

template<>
struct st_time<std::chrono::seconds>
{
	static const bool val = true;
	using type = std::chrono::seconds;
};

template<>
struct st_time<std::chrono::minutes>
{
	static const bool val = true;
	using type = std::chrono::minutes;
};

template<>
struct st_time<std::chrono::hours>
{
	static const bool val = true;
	using type = std::chrono::hours;
};

//value template using constexpr keyword
template<typename T>
constexpr bool is_timeunit = st_time<T>::val; // compile time resolution

template<typename T>
using timeunit_t = typename st_time<T>::type;
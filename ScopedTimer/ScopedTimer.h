#pragma once

#include <functional>
#include <chrono>
#include <iostream>

#include "Types/TimeTypes.h"
#include "Types/SameCheck.h"

template<typename T, typename = st_time<T>>
struct TimerRes
{
	void operator()(const int t) const
	{
		if (is_same_v<T, std::chrono::nanoseconds>)
		{
			std::cout << "Duration: " << t << "ns" << '\n';
		}
		else if (is_same_v<T, std::chrono::milliseconds>)
		{
			std::cout << "Duration: " << t << "ms" << '\n';
		}
		else if (is_same_v<T, std::chrono::seconds>)
		{
			std::cout << "Duration: " << t << "s" << '\n';
		}
		else if (is_same_v<T, std::chrono::minutes>)
		{
			std::cout << "Duration: " << t << "mins" << '\n';
		}
		else if (is_same_v<T, std::chrono::hours>)
		{
			std::cout << "Duration: " << t << "hrs" << '\n';
		}
	}
};

//SFINAE out all other units of time except for the ones specialized
template<typename T, typename = st_time<T>>
class ScopedTimer
{
private:
	std::chrono::high_resolution_clock::time_point t0_;
	std::chrono::high_resolution_clock::time_point t1_;
	std::function<void(int)> callback_;
public:
	ScopedTimer() : t0_(std::chrono::high_resolution_clock::now()),
		callback_(TimerRes<T>())
	{
	}

	ScopedTimer(std::function<void(int)> callback) :
		t0_(std::chrono::high_resolution_clock::now()),
		callback_(callback)
	{
	}

	~ScopedTimer()
	{
		t1_ = std::chrono::high_resolution_clock::now();
		const int elapsed = std::chrono::duration_cast<T>(t1_ - t0_).count();

		callback_(elapsed);
	}
};
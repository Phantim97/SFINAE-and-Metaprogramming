#include "../Types/IntegralTypes.h" //Checks for integral types
#include "../Types/NumericTypes.h" //Checks for numeric types
#include <iostream>

//SFINAE out all non numerics for numeric_t checks and all non-integral types for integer_t checks
template<typename T, typename = numeric_t<T>>
class MetaCalculator
{
private:
	T _val;
	bool _print_enabled = false;
	void _print_result() const
	{
		if (this->_print_enabled)
		{
			std::cout << "Result: " << this->_val << '\n';
		}
	}

public:
	MetaCalculator(T v)
	{
		this->_val = v;
	}

	void clear()
	{
		this->_val = 0;
	}

	void toggle_result_printing()
	{
		this->_print_enabled = !this->_print_enabled;
		if (this->_print_enabled)
		{
			std::cout << "Result Printing Enabled\n";
		}
	}

	//SFINAE out float and doubles for numeric_t cases
	template<typename S, typename = numeric_t<S>>
	T operator+(const S& v)
	{
		this->_val += static_cast<T>(v);
		this->_print_result();
		return this->_val;
	}

	template<typename S, typename = numeric_t<S>>
	T operator-(const S& v)
	{
		this->_val -= static_cast<T>(v);
		this->_print_result();
		return this->_val;
	}

	template<typename S, typename = numeric_t<S>>
	T operator*(const S& v)
	{
		this->_val *= static_cast<T>(v);
		this->_print_result();
		return this->_val;
	}

	template<typename S, typename = numeric_t<S>>
	T operator/(const S& v)
	{
		this->_val /= static_cast<T>(v);
		this->_print_result();
		return this->_val;
	}

	//SFINAE out all non-integral types for our exponent
	template<typename S, typename = integer_t<S>>
	T operator^(const S& v)
	{
		this->_val = static_cast<T>(std::pow(this->_val, v)); //Static casted here because pow implicitly casts
		this->_print_result();
		return this->_val;
	}

	template<typename S, typename = integer_t<S>>
	same_t<T, S> operator%(const S& v)
	{
		this->_val %= static_cast<T>(v);
		this->_print_result();
		return this->_val;
	}

	friend std::ostream& operator<<(std::ostream& os, const MetaCalculator mc)
	{
		os << mc._val;
		return os;
	}
};
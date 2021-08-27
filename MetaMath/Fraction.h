#include "../Types/IntegralTypes.h"

//Placeholder until Template Class operations are resolved resolved.
#ifdef WIP
//Must have an integral type to be a fraction
template<typename T, typename = integer_t<T>>
class Fraction
{
private:
	T _numer;
	T _denom;
public:
	Fraction(T n, T d)
	{
		_numer = n;
		_denom = d;
	}

	template<typename S, typename = integer_t<S>>
	friend Fraction<T> operator+(const Fraction<S>& other)
	{
		return Fraction((this->_numer * static_cast<T>(other._denom)) + (static_cast<T>(other._numer) * this->_denom),
			(this->_denom * static_cast<T>(other->_denom)));
	}

	template<typename S, typename = integer_t<S>>
	friend Fraction operator-(const Fraction<S>& other)
	{
		return Fraction((this->_numer * other._denom) - (other._numer * this->_denom),
			(this->_denom * other->_denom));
	}

	template<typename S, typename = integer_t<S>>
	friend Fraction operator*(const Fraction<S>& other)
	{
		return Fraction((this->_numer * other._numer), (this->_denom * other->_denom));
	}

	template<typename S, typename = integer_t<S>>
	Fraction operator/(const Fraction<S>& other)
	{
		return Fraction((this->_numer * other._denom), (this->_denom * other._numer));
	}

	friend std::ostream& operator<<(std::ostream& os, const Fraction f)
	{
		os << f._numer << "/" << f._denom;
		return os;
	}

	double decimal_representation()
	{
		return this->_numer / this->denom;
	}
};
#endif
#include "../Types/IntegralTypes.h"

//Must have an integral type to be a fraction
template<typename T, typename R, typename = integer_t<T>, typename = integer_t<R>>
class Fraction
{
private:
	T _numer;
	R _denom;
public:
	Fraction(T n, R d)
	{
		_numer = n;
		_denom = d;
	}

	//These getters are used for the operators to remove the "friend"
	//keyowrd which caused compile errors when using the operators.
	T n() const { return this->_numer; }
	R d() const { return this->_numer; }

	template<typename S, typename Q, typename = integer_t<S>, typename = integer_t<Q>>
	Fraction operator+(const Fraction<S, Q>& other)
	{
		return Fraction((this->_numer * static_cast<T>(other.d())) + (static_cast<T>(other.n()) * this->_denom),
			(this->_denom * static_cast<T>(other.d())));
	}

	template<typename S, typename Q, typename = integer_t<S>, typename = integer_t<Q>>
	Fraction operator-(const Fraction<S, Q>& other)
	{
		return Fraction((this->_numer * other.d()) - (other.n() * this->_denom),
			(this->_denom * other.d()));
	}

	template<typename S, typename Q, typename = integer_t<S>, typename = integer_t<Q>>
	Fraction operator*(const Fraction<S, Q>& other)
	{
		return Fraction((this->_numer * other.n()), (this->_denom * other.d()));
	}

	template<typename S, typename Q, typename = integer_t<S>, typename = integer_t<Q>>
	Fraction operator/(const Fraction<S, Q>& other)
	{
		return Fraction((this->_numer * other.d()), (this->_denom * other.n()));
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
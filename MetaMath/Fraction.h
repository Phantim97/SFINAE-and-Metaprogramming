#include "../Types/IntegralTypes.h"

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

	//These getters are used for the operators to remove the "friend"
	//keyowrd which caused compile errors when using the operators.
	T n() const { return this->_numer; }
	T d() const { return this->_numer; }

	template<typename S, typename = integer_t<S>>
	Fraction operator+(const Fraction<S>& other)
	{
		return Fraction((this->_numer * static_cast<T>(other.d())) + (static_cast<T>(other.n()) * this->_denom),
			(this->_denom * static_cast<T>(other.d())));
	}

	template<typename S, typename = integer_t<S>>
	Fraction operator-(const Fraction<S>& other)
	{
		return Fraction((this->_numer * other.d()) - (other.n() * this->_denom),
			(this->_denom * other.d()));
	}

	template<typename S, typename = integer_t<S>>
	Fraction operator*(const Fraction<S>& other)
	{
		return Fraction((this->_numer * other.n()), (this->_denom * other.d()));
	}

	template<typename S, typename = integer_t<S>>
	Fraction operator/(const Fraction<S>& other)
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
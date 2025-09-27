#pragma once


class Fraction
{
	int numerator = 0;
	int denominator = 1;

public:
	Fraction() = default;
	Fraction(int numerator, int denominator);


	void print() const;
	void setNumerator(int numerator);
	int getNumerator() const;
	void setDenominator(int denominator);
	int getDenominator() const;

	Fraction add(const Fraction& obj) const;
	Fraction sub(const Fraction& obj) const;
	Fraction mul(const Fraction& obj) const;
	Fraction div(const Fraction& obj) const;

	Fraction operator-()
	{
		return Fraction(-numerator, denominator);
	}


	Fraction operator++() // Prefix
	{
		numerator += denominator;
		return *this;
	}

	Fraction operator++(int) // Postfix
	{
		Fraction temp(numerator, denominator);
		numerator += denominator;
		return temp;
	}

	Fraction operator+(const Fraction& f)
	{
		int num = numerator * f.denominator + f.numerator * denominator;
		int den = denominator * f.denominator;
		return Fraction(num, den);
	}

	Fraction operator-(const Fraction& f)
	{
		int num = numerator * f.denominator - f.numerator * denominator;
		int den = denominator * f.denominator;
		return Fraction(num, den);
	}

	Fraction operator*(const Fraction& f)
	{
		int num = numerator * f.numerator;
		int den = denominator * f.denominator;
		return Fraction(num, den);
	}

	Fraction operator/(const Fraction& f)
	{
		int num = numerator * f.denominator;
		int den = denominator * f.numerator;
		return Fraction(num, den);
	}


	Fraction& operator+=(const Fraction& f)
	{
		*this = *this + f;
		return *this;
	}

	Fraction operator+(int obj)
	{
		return *this + Fraction(obj, 1);
	}

	bool operator>(const Fraction& f) const
	{
		return (float)numerator / denominator > (float)f.numerator / f.denominator;
	}

	bool operator<(const Fraction& f) const
	{
		return (float)numerator / denominator < (float)f.numerator / f.denominator;
	}

	bool operator==(const Fraction& f) const
	{
		return (float)numerator / denominator == (float)f.numerator / f.denominator;
	}

};


Fraction operator+(int value, const Fraction& f)
{
	return Fraction(value, 1) + f;
}


inline Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	if (denominator == 0)
	{
		denominator = 1;
	}
	this->denominator = denominator;
}

void Fraction::print() const
{
	cout << numerator << "/" << denominator << endl;
}

inline void Fraction::setNumerator(int numerator)
{
	this->numerator = numerator;
}

inline int Fraction::getNumerator() const
{
	return numerator;
}

inline void Fraction::setDenominator(int denominator)
{
	if (denominator == 0)
	{
		denominator = 1;
	}
	this->denominator = denominator;
}

inline int Fraction::getDenominator() const
{
	return denominator;
}

Fraction operator-(const Fraction& f)
{
	return Fraction(-f.getNumerator(), f.getDenominator());
}
#include <iostream>
class Fixed
{
	private:
	int					value;
	static const int	frac = 8;

	public:
	Fixed();
	Fixed(const int raw);
	Fixed(const float decimal);
	Fixed(const Fixed& copy);
	Fixed& operator =(const Fixed& rhs);
	friend std::ostream& operator <<(std::ostream& os, const Fixed& rhs);

	~Fixed();

	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(const int raw);
};
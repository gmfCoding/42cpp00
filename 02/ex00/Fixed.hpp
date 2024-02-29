class Fixed
{
	private:
	int					value;
	static const int	frac = 8;

	public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator =(const Fixed& rhs);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(const int raw);
};
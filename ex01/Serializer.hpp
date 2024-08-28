#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer& copy);
		Serializer& operator =(Serializer& rhs);
		~Serializer();

	public:
		uintptr_t serialize(Data* ptr);
		Data* deserailize(uintptr_t raw);
};
#endif

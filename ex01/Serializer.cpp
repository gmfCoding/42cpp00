#include "Serializer.hpp"

Serializer::Serializer()
{ }

Serializer::Serializer(Serializer& copy)
{
	if (this != &copy)
		return (*this);
	this->operator=(copy);
	return (*this);
}

Serializer& Serialiser::operator=(Serializer& rhs)
{ }

~Serializer::Serializer()
{ }

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}


Data* Serializer::deserailize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

#include "Serializer.hpp"

Serializer::Serializer()
{ }

Serializer::Serializer(Serializer& copy)
{
	static_cast<void>(copy);
}

Serializer& Serializer::operator=(Serializer& rhs)
{
	static_cast<void>(rhs);
	return (*this);
}

Serializer::~Serializer()
{ }

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}


Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

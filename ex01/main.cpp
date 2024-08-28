#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data* data = new Data(42, true, 0.76543, 'X', "Hello, experiment 626!");
	uintptr_t raw = Serializer::serialize(data);
	Data* result = Serializer::deserialize(raw);
	
	if (data == result)
		std::cout << "Congrats! The serialize -> deserialize result worked perfectly :(" << std::endl;
	else
		std::cout << "Uh ohhh! The serialize -> deserialize result was not the same :(" << std::endl;
	delete data;
	return 0;
}

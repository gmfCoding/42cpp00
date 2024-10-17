#include "BTCDate.hpp"

BTCDate::BTCDate()  : dateval(0), datestr(""), value(0)
{

}

BTCDate::BTCDate(ulong64 dateval, const std::string& datestr, const float value) : dateval(dateval), datestr(datestr), value(value)
{
	
}


// BTCDate& BTCDate::operator=(const BTCDate &rhs)
// {


// }

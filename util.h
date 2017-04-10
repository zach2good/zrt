#ifndef ZRT_UTIL
#define ZRT_UTIL

#include<iostream>
#include<string>
#include<sstream>	

namespace zrt
{
	// From http://www.stroustrup.com/bs_faq2.html#int-to-string
	// Thanks Bjarne!
	std::string itos(int i)	// convert int to string
	{
		std::stringstream s;
		s << i;
		return s.str();
	}
} // namespace zrt 

#endif // ZRT_UTIL
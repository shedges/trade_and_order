#ifndef _COMMON_H_
#define _COMMON_H_

#include <limits>
#include <cstddef>
#include <string.h>

struct err_stats {
	err_stats () 
	{
		mCorruptMessage = 0ULL;
		mDuplicateEntry = 0ULL;
		mInvalidEntry = 0ULL;
	}
	unsigned long long mCorruptMessage;
	unsigned long long mDuplicateEntry;
	unsigned long long mInvalidEntry;
	
};

inline bool convertStrToUINT(std::string str, unsigned int &value)
{
	char *end;
	long long num = strtoll(str.c_str (), &end, 10);			//Convert to long long to support 32-bit.
	if (end == str)
	{
		return false;
	}
	if ( (num < std::numeric_limits<unsigned int>::min()) || (num > std::numeric_limits<unsigned int>::max()))	//Check whether converted value (long long) greater than positive interger.
	{
		return false;
	}

	value = num;
	return true;
}

inline bool convertStrToDouble(std::string str, double &value)
{
	char *end;
	double num = strtod (str.c_str (), &end);
	if (end == str)
	{
		return false;
	}
	if ( (num < std::numeric_limits<double>::min()) || (num > std::numeric_limits<double>::max()))
	{
		return false;
	}

	value = num;
	return true;
}

#endif

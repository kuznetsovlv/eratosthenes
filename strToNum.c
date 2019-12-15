#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "strToNum.h"

unsigned long long strToNum(const char *str)
{
	const char *s = str;
	unsigned long long res = 0, prev = 0;

	while(*s)
	{
		if(*s < '0' || *s > '9')
		{
			fprintf(stderr, "%s is not a valid number value.\n", str);
			exit(1);
		}

		res *= 10;
		res += *s - '0';

		if(res < prev)
		{
			fprintf(stderr, "%s is out of available range [%u, %llu]\n", str, 0, ULLONG_MAX);
			exit(1);
		}

		prev = res;
		++s;
	}

	return res;
}

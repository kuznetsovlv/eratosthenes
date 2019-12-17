#include <math.h>

#include "prime.h"
#include "mem.h"

int __upToCheck(void *, unsigned long long, unsigned long long);
int __numsCheck(void *, unsigned long long, unsigned long long);
checker __getChecker(Variant);

unsigned estimate(unsigned long long n)
{
	return (unsigned) ceill(logl(n) / n);
}

void *getPrimes(unsigned long long limit, Variant variant, void (*onPrime)(unsigned long long))
{
	switch (variant)
	{
		case upTo:
			if(limit < 2) return getMem(0);
			break;
		case nums:
			if(limit) return getMem(0);
			break;
	}

	void *list = getMem(variant == upTo ? estimate(limit) : limit);

	checker check = __getChecker(variant);

	unsigned long long i = 2;

	while(check(list, limit, i))
	{
	}

	return list;
}

int __upToCheck(void *list, unsigned long long limit, unsigned long long num)
{
	return num <= limit;
}

int __numsCheck(void *list, unsigned long long limit, unsigned long long num)
{
	return filled(list) < limit;
}

checker __getChecker(Variant variant)
{
	return variant == upTo ? __upToCheck : __numsCheck;
}

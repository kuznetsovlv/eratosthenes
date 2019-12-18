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

void *eratosthenes(unsigned long long limit, Variant variant, void (*onPrime)(unsigned long long))
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

	list = putItem(list, i);

	onPrime(i++);

	while(check(list, limit, i))
	{
		unsigned long long r = (unsigned long long)ceill(sqrtl(i));

		unsigned j;
		unsigned long long item;
		int isPrime;
		for(j = 0; j < filled(list) && (item = getItem(list, j)) <= r && (isPrime = (i % item)); ++j);

		if(isPrime)
		{
			if(filled(list) == size(list)) list = addMem(list, estimate(limit - getItem(list, filled(list) - 1)));
			list = putItem(list, i);
			onPrime(i);
		}

		i += 2;
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

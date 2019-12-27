#include <math.h>

#include "prime.h"
#include "mem.h"

int __isPrime(void *, unsigned long long);

size_t estimate(unsigned long long n)
{
	long double size = 0.0;

	for(unsigned long long i = 2; i <= n; ++i)
		size += 1.0/logl(i);
	return (size_t) ceill(size);
}

void *eratosthenes(Config config)
{
	void *list = config.initMem();
	unsigned long long i = 2;

	list = config.addItem(list, i);

	config.onPrime(i++);

	while(config.hasNext(list, i))
	{
		if(__isPrime(list, i))
		{
			list = config.addItem(list, i);
			config.onPrime(i);
		}

		i += 2;
	}

	return list;
}

int __isPrime(void *list, unsigned long long x)
{
	unsigned long long sqroot = (unsigned long long)ceil(sqrtl(x));

	unsigned i;
	unsigned long long item;
	int isPrime;

	for(i = 0; i < filled(list) && (item = getItem(list, i)) <= sqroot && (isPrime = (x % item)); ++i);

	return isPrime;
}

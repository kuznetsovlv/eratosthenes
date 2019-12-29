#include <stdio.h>

#include "mem.h"
#include "strToNum.h"
#include "prime.h"

void __printNumber(unsigned long long);

int main(int argc, char **argvs)
{
	if (argc < 2)
	{
		fprintf(stderr, "No arguments\n");
		exit(1);
	}

	unsigned long long num = 0;

	for(int i = 1; i < argc; ++i)
	{
		unsigned long long r = strToNum(*(argvs + i));
		if (r > num) num = r;
	}

	void *initMem(void)
	{
		return getMem(estimate(num));
	}

	void *addItem(void *list, unsigned long long val)
	{
		if(size(list) == filled(list))
		{
			list = addMem(list, (val - getLast(list)) / 2);
		}

		return putItem(list, val);
	}

	int hasNext(void *list, unsigned long long val)
	{
		return val <= num;
	}

	Config config = {
		initMem, addItem, hasNext, __printNumber
	};

	free (eratosthenes(config));

	return 0;
}

void __printNumber(unsigned long long x)
{
	printf("%llu\n", x);
}

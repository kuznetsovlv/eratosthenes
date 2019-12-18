#include <stdio.h>
#include <stdlib.h>

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

	getPrimes(num, upTo, __printNumber);

	return 0;
}

void __printNumber(unsigned long long x)
{
	printf("%llu\n", x);
}

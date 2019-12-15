#include <stdio.h>
#include <stdlib.h>

#include "mem.h"

int main(int argc, char **argvs)
{
	printf("Started\n");

	unsigned *p = (unsigned *)getMem(4);
	printf("%u %u\n", size(p), filled(p));
	p = (unsigned *)addMem(p, 4);
	printf("%u %u\n", size(p), filled(p));

	for(unsigned i = 0; i < 12; ++i)
	{
		p = putItem(p, i);
		printf("%u %u\n", size(p), filled(p));
	}

	for(unsigned i = 0; i < filled(p); ++i)
		printf("%llu\t", getItem(p, i));

	printf("\n");

	free(p);
	return 0;
}

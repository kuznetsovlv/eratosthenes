#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "strToNum.h"
#include "simple.h"

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

	if(num >= 2)
	{
		void *list = getMem(estimate(num));

		for(unsigned long long i = 2; i <= num; ++i)
		{
			if(!filled(list))
			{
				list = putItem(list, i);
				printf("%llu\n", i);
			}
			else
			{
				unsigned j;
				for(j = 0; j < filled(list); ++j)
				{
					if(!(i % getItem(list, j))) break;
				}

				if(j == filled(list))
				{
					printf("%llu\n", i);
					if(filled(list) == size(list)) list = addMem(list, estimate(num - getItem(list, filled(list) -1)));
					list = putItem(list, i);
				}
			}
		}
	}
	return 0;
}

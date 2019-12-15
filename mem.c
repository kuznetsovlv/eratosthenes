#include <stdio.h>
#include <stdlib.h>
#include "mem.h"

size_t __getSize(unsigned);

void *getMem(unsigned length)
{
	void *p = malloc(__getSize(length));

	if(p == NULL)
	{
		fprintf(stderr, "Can not allocate memory");
		exit(1);
	}

	*(unsigned *)p = length;
	*((unsigned *)p + 1) = 0;
	return p;
}

void *addMem(void *mem, unsigned add)
{
	unsigned length = *(unsigned *)mem + add;

	if(length < *(unsigned *)mem)
	{
		fprintf(stderr, "Memory limit exceeded.\n");
		exit(1);
	}

	mem = realloc(mem, __getSize(length));

	if(mem == NULL)
	{
		fprintf(stderr, "Can not allocate memory");
		exit(1);
	}

	*(unsigned *)mem = length;
	return mem;
}

void *putItem(void *mem, unsigned long long x)
{
	unsigned length = *(unsigned *)mem;
	unsigned filled = *((unsigned *)mem + 1);

	if (length < filled)
	{
		fprintf(stderr, "Memory broken.\n");
		exit(1);
	}
	if (length == filled)
	{
		mem = addMem(mem, 1);
	}

	unsigned long long *arr = (unsigned long long *)((unsigned *)mem + 2);

	*(arr + filled) = x;
	*((unsigned *)mem + 1) = filled + 1;

	return mem;
}

unsigned long long getItem(void *mem, unsigned i)
{
	return *((unsigned long long *)((unsigned *)mem + 2) + i);
}

unsigned size(void *mem)
{
	return *(unsigned *)mem;
}

unsigned filled(void *mem)
{
	return *((unsigned *)mem + 1);
}

size_t __getSize(unsigned length)
{
	if(~(size_t)0 - 2 * sizeof(unsigned long long) < length)
	{
		fprintf(stderr, "Memory limit exceeded.\n");
		exit(1);
	}
	return 2 * sizeof(unsigned) + length * sizeof(unsigned long long);
}

#include <stdio.h>
#include "mem.h"

size_t __getSize(size_t);
void __setSize(void *, size_t);
void __setFilled(void *, size_t);

void *getMem(size_t length)
{
	void *p = malloc(__getSize(length));

	if(p == NULL)
	{
		fprintf(stderr, "Can not allocate memory");
		exit(1);
	}

	__setSize(p, length);
	__setFilled(p, 0);
	return p;
}

void *addMem(void *mem, size_t add)
{
	size_t length = *(size_t *)mem + add;

	if(length < *(size_t *)mem)
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

	__setSize(mem, length);
	return mem;
}

void *putItem(void *mem, unsigned long long x)
{
	size_t length = size(mem);
	size_t filledFields = filled(mem);

	if (length < filledFields)
	{
		fprintf(stderr, "Memory broken.\n");
		exit(1);
	}
	if (length == filledFields)
	{
		mem = addMem(mem, 1);
	}

	unsigned long long *arr = (unsigned long long *)((size_t *)mem + 2);

	*(arr + filledFields) = x;
	__setFilled(mem, ++filledFields);

	return mem;
}

unsigned long long getItem(void *mem, size_t i)
{
	return *((unsigned long long *)((size_t *)mem + 2) + i);
}

unsigned long long getLast(void *mem)
{
	return getItem(mem, filled(mem) - 1);
}

size_t size(void *mem)
{
	return *(size_t *)mem;
}

size_t filled(void *mem)
{
	return *((size_t *)mem + 1);
}

size_t __getSize(size_t length)
{
	if(~(size_t)0 - 2 * sizeof(unsigned long long) < length)
	{
		fprintf(stderr, "Memory limit exceeded.\n");
		exit(1);
	}
	return 2 * sizeof(size_t) + length * sizeof(unsigned long long);
}

void __setSize(void *mem, size_t size)
{
	*(size_t *)mem = size;
}

void __setFilled(void *mem, size_t filled)
{
	*((size_t *)mem + 1) = filled;
}

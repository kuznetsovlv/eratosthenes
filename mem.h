#ifndef __MEMORIZE
#define __MEMORIZE
#include <stdlib.h>
void *getMem(size_t);
void *addMem(void *, size_t);
void *putItem(void *, unsigned long long);
unsigned long long getItem(void *, size_t);
unsigned long long getLast(void *);
size_t size(void *);
size_t filled(void *);
#endif

#ifndef __MEMORIZE
#define __MEMORIZE
void *getMem(unsigned);
void *addMem(void *, unsigned);
void *putItem(void *, unsigned long long);
unsigned long long getItem(void *, unsigned);
unsigned size(void *);
unsigned filled(void *);
#endif

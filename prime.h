#ifndef __SIMPLE
#define __SIMPLE
typedef enum Variant {upTo, nums} Variant;
typedef int (*checker)(void *, unsigned long long, unsigned long long);
unsigned estimate(unsigned long long);
void *getPrimes(unsigned long long, Variant, void(*)(unsigned long long));
#endif

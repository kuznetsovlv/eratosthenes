#ifndef __PRIME
#define __PRIME
#include <stdlib.h>
typedef void *(*init_mem)(void);
typedef void *(*add_item)(void *, unsigned long long);
typedef int (*has_next)(void *, unsigned long long);
typedef void (*on_prime)(unsigned long long);
typedef struct Config {
	init_mem initMem;
	add_item addItem;
	has_next hasNext;
	on_prime onPrime;
} Config;
size_t estimate(unsigned long long);
void *eratosthenes(Config);
#endif

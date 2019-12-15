#include <math.h>

unsigned estimate(unsigned long long n)
{
	return (unsigned) ceill(logl(n) / n);
}

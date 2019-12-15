#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "strToNum.h"

int main(int argc, char **argvs)
{
	printf("%llu\n", strToNum("0"));
	printf("%llu\n", strToNum("24"));
	printf("%llu\n", strToNum("18446744073709551615"));
	printf("%llu\n", strToNum("184467440737095516150"));
	return 0;
}

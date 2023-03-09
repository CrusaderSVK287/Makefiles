#include "calc_test.h"
#include <calc.h>
#include <stdio.h>

#define assert(func) {if (func) puts("passed"); else puts("failed");}

void test_calc()
{
	assert(calc(10,5) == 15);
	assert(calc(5,5) == -1);
	assert(calc(10,8) == 15);
}


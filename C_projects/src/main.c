#include "calc.h"
#include "hello.h"
#include "nested/nested.h"

int main()
{
	int ret = calc(5, 10);

	hello(ret);

	nested();

	return 0;
}


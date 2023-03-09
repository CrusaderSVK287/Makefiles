#include "nested.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void nested()
{
	srand(time(NULL));
	switch (rand() % 3) {
		case 0: puts("0"); break;
		case 1: puts("1"); break;
		case 2: puts("2"); break;
		default: break;
	}
}


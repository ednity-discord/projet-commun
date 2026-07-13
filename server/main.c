#include "error.h"
#include <stdio.h>

int
main(void)
{
	printf("this is the server\n");
	ERROR("this is an error\n");
	return 0;
}

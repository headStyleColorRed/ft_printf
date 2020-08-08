#include "printf_lib.h"
#include <limits.h>

int main(void)
{
	int my_total;
	int his_total;

	my_total = ft_printf("hello, %s.\n", "gavin");
	his_total = printf("hello, %s.\n", "gavin");
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);
	
}
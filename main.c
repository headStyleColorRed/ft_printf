#include "printf_lib.h"
#include <limits.h>

int main(void)
{
	int my_total;
	int his_total;

	my_total = ft_printf("|%-8.3X|\n", 8375);
	his_total = printf("|%-8.3X|\n", 8375);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);
	
}
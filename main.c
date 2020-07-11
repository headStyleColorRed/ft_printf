#include "printf_lib.h"
#include <limits.h>

int main(void)
{
	int my_total;
	// int his_total;

	my_total = ft_printf("%-5.46d\n", 5);
	// his_total = printf("%");
	printf("My  total -> %d\n", my_total);
	// printf("His total -> %d\n\n", his_total);
	
}
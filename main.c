#include "printf_lib.h"
#include <limits.h>

int main(void)
{
	int my_total;
	int his_total;

	int *ptr_my_total = &my_total;
	int *ptr_his_total = &his_total;

	my_total = ft_printf("|%p|, |%p|\n", ptr_my_total, ptr_his_total);
	his_total = printf("|%p|, |%p|\n", ptr_my_total, ptr_his_total);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);
	
}
#include "printf_lib.h"

int main(void)
{
	int my_total;
	int his_total;


	my_total = ft_printf("|%d|\n", -2147483648);
	his_total = printf"|%d|\n", -2147483648);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n\n", his_total);





}
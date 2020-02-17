#include "printf_lib.h"

int main(void)
{
	int my_total;
	int his_total;


	my_total = ft_printf("|%-5.0i|\n", 0);
	his_total = printf("|%-5.0i|\n", 0);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n\n", his_total);

	printf("\n");


	my_total = ft_printf("|%5.0i|\n", 0);
	his_total = printf("|%5.0i|\n", 0);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n\n", his_total);




}
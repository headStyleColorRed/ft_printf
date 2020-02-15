#include "printf_lib.h"

int main(void)
{
	int my_total;
	int his_total;


	my_total = ft_printf("%10.5i\n", -216);
	his_total = printf("%10.5i\n", -216);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n\n", his_total);




/*
	my_total = ft_printf("%i\n",-23646);
	his_total = printf("%i\n",-23646);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n\n", his_total);
	*/

	/*
	my_total = ft_printf("%.3i\n",-23646);
	his_total = printf("%.3i\n",-23646);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n\n", his_total);
	*/
}
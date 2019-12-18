#include "printf_lib.h"

int main(void)
{
	int my_total;
	int his_total;

	my_total = ft_printf("%.3i\n",-23646);
	his_total = printf("%.3i\n",-23646);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n\n", his_total);

	/*

		my_total = ft_printf("%.6d\n", -3);
		his_total = printf("%.6d\n", -3);
		printf("My total -> %d\n", my_total);
		printf("Histotal -> %d\n", his_total);
		*/
}
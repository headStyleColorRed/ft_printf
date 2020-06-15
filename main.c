#include "printf_lib.h"
#include <limits.h>

int main(void)
{
	int my_total;
	int his_total;

	my_total = ft_printf("Hola Rodrigo |%d|\n", INT_MIN);
	his_total = printf("Hola Rodrigo |%d|\n", INT_MIN);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);

// printf("\n\n\n\n");


// 	my_total = ft_printf("Hola Rodrigo |%d|\n", -200);
// 	his_total = printf("Hola Rodrigo |%d|\n", -200);
// 	printf("My  total -> %d\n", my_total);
// 	printf("His total -> %d\n\n", his_total);
	
}

#include "printf_lib.h"
#include <limits.h>

int main(void)
{
	int my_total;
	int his_total;

	my_total = ft_printf("Hola Rodrigo |%-3s|\n", "hello");
	his_total = printf("Hola Rodrigo |%-3s|\n", "hello");
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);
	
}

#include "printf_lib.h"
#include <limits.h>

int main(void)
{
	int my_total;
	int his_total;

	my_total = ft_printf("|%.*s|\n", -3, "hello");
	his_total = printf("|%.*s|\n", -3, "hello");
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);

	my_total = ft_printf("|%-*.*s|\n", -7, -3, "yolo");
	his_total = printf("|%-*.*s|\n", -7, -3, "yolo");
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);
	
}

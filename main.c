#include "printf_lib.h"

int main(void)
{
	int my_total;
	int his_total;
	// 4294967295
	unsigned int biggerPrecision = 4294967295;
	const char *greetings = "Hola";

	/*
		my_total = ft_printf("Hola Rodrigo |%-5c|\n", 'a');
		his_total = printf("Hola Rodrigo |%-5c|\n", 'a');
		printf("My  total -> %d\n", my_total);
		printf("His total -> %d\n\n", his_total);
	*/

	my_total = ft_printf("|%-8x|\n", 1234);
	  his_total = printf("|%-8x|\n", 1234);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n", his_total);
}

#include "printf_lib.h"

int main(void)
{
	int my_total;
	int his_total;
	// 4294967295
	int Precision = 4294967295;
	unsigned int biggerPrecision = (unsigned int)Precision;
	const char *greetings = "Hola";

	/*
		my_total = ft_printf("Hola Rodrigo |%-5c|\n", 'a');
		his_total = printf("Hola Rodrigo |%-5c|\n", 'a');
		printf("My  total -> %d\n", my_total);
		printf("His total -> %d\n\n", his_total);
	*/

	my_total = ft_printf("|%u|\n", 4294967295);
	  his_total = printf("|%u|\n", biggerPrecision);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n", his_total);
}

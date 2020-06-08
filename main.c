#include "printf_lib.h"

int main(void)
{
	int my_total;
	int his_total;
	int *ptr = &his_total;

	my_total = ft_printf("Hola Rodrigo |%-5c|\n", 'a');
	his_total = printf("Hola Rodrigo |%-5c|\n", 'a');
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);
	
	// char
	ft_printf("Hola Rodrigo |%-5c|\n", 'a');
	// string
	ft_printf("Hola Rodrigo |%-5s|\n", "it works!");
	// pointer
	ft_printf("Hola Rodrigo |%p|\n", ptr);
	//int
	ft_printf("Hola Rodrigo |%d|\n", 345);
	// unsigned
	ft_printf("Hola Rodrigo |%d|\n", 3453);
	// hexadecimal min
	ft_printf("Hola Rodrigo |%x|\n", 345);
	//hexadecimal max
	ft_printf("Hola Rodrigo |%X|\n", 345);
	
}

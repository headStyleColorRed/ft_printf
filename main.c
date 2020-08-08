#include "printf_lib.h"
#include <limits.h>

int main(void)
{
	int my_total;
	// int his_total;
	static char *s_hidden = "hi low\0don't print me lol\0";

	my_total = ft_printf("%00s", s_hidden);
	// his_total = printf("%0-3.7u", 3267);
	// printf("My  total -> %d\n", my_total);
	// printf("His total -> %d\n\n", his_total);
	
}
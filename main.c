#include "printf_lib.h"
#include <limits.h>
#include <assert.h>

int main(void)
{
	char c = 'y';

	assert(printf("-->|%--4.c|<--\n", c) == ft_printf("-->|%--4.c|<--\n", c));
	assert(printf("-->|%--3.c|<--\n", c) == ft_printf("-->|%--3.c|<--\n", c));
	assert(printf("-->|%--3c|<--\n", c) == ft_printf("-->|%--3c|<--\n", c));
	assert(printf("-->|%--2.c|<--\n", c) == ft_printf("-->|%--2.c|<--\n", c));
	assert(printf("-->|%--2c|<--\n", c) == ft_printf("-->|%--2c|<--\n", c));
	assert(printf("-->|%--1.c|<--\n", c) == ft_printf("-->|%--1.c|<--\n", c));
	assert(printf("-->|%--1c|<--\n", c) == ft_printf("-->|%--1c|<--\n", c));

		int my_total;
	int his_total;

	my_total = ft_printf("-->|%--4.c|<--\n", c);
	his_total = printf("-->|%--4.c|<--\n", c);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);
}

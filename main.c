#include "printf_lib.h"
#include <limits.h>
#include <assert.h>

void test_different_d();
int main(void)
{
	// int my_total;
	// int his_total;
	// int exittab[] = {-135, -12, -1, 0, 1, 13, 198, -2147483648, INT_MAX};
	// int i = 2;
	// 	my_total = ft_printf("-->|%5.3d|<--\n", exittab[i]);
	// 	his_total = printf("-->|%5.3d|<--\n", exittab[i]);
	// 	printf("My  total -> %d\n", my_total);
	// 	printf("His total -> %d\n\n", his_total);

	// ft_printf("-->|%5.3d|<--\n", -1);
	//    printf("-->|%5.3d|<--\n", -1);

	// ft_printf("-->|%*.*d|<--\n", 4, 1, 0);
	//    printf("-->|%*.*d|<--\n", 4, 1, 0);

	test_different_d();
	return (0);
}

void test_different_d()
{
	int my_total;
	int his_total;
	int i;
	int exittab[] = {-135, -12, -1, 0, 1, 13, 198, INT_MIN, INT_MAX};
	int exit_length = sizeof(exittab) / sizeof(exittab[0]);

	// exit_length = 3;
	i = 0;
	while (i < (int)exit_length)
	{
		my_total = ft_printf("-->|%0*.d|<--\n", 3, exittab[i]);
		his_total = printf("-->|%0*.d|<--\n", 3, exittab[i]);
		printf("My  total -> %d\n", my_total);
		printf("His total -> %d\n\n", his_total);
		i++;
	}

	my_total = ft_printf("-->|%5.3d|<--\n", -1);
	his_total = printf("-->|%5.3d|<--\n", -1);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);


	my_total = ft_printf("-->|%10.5d|<--\n", -216);
	his_total = printf("-->|%10.5d|<--\n", -216);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);


	my_total = ft_printf("-->|%08.3i|<--\n", -8473);
	his_total = printf("-->|%08.3i|<--\n", -8473);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);


	my_total = ft_printf("-->|%0*.d|<--\n", 4, -12);
	his_total = printf("-->|%0*.d|<--\n", 4, -12);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);



	my_total = ft_printf("-->|%0*.d|<--\n", 3, -1);
	his_total = printf("-->|%0*.d|<--\n", 3, -1);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);



	my_total = ft_printf("-->|%*.*d|<--\n", 4, 2, -1);
	his_total = printf("-->|%*.*d|<--\n", 4, 2, -1);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n\n", his_total);
}
// -->|  -8473|<--
// -->|   -8473|<--
// //  12345678911
// //		    01







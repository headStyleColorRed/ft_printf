#include "../printf_lib.h"


void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check_base(char *base)
{
	int i;
	int z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

int ft_putnbr_base(unsigned long long int nbr, int base_type)
{
	char *base;
	char *final_number;
	int size_base;
	int nbr_final[100];
	int i;
	int z;
	if (base_type == 1)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	i = 0;
	size_base = 0;

	final_number = ft_calloc(50, 1);
	while (base[size_base])
		size_base++;
	while (nbr)
	{
		nbr_final[i++] = nbr % size_base;
		nbr = nbr / size_base;
	}
	z = 0;
	if (get_wordifier(type_is_ptr) == 1)
	{
		final_number[0] = '0';
		final_number[1] = 'x';
		z += 2;
	}

	while (--i >= 0)
		final_number[z++] = base[nbr_final[i]];
	if (get_wordifier(type_is_hex) == 1)
		print_unmodified_s(final_number);
	else
		print_s(final_number);
	free(final_number);
	return (z);
}
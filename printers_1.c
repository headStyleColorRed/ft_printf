#include "printf_lib.h"

void print_c(int character)
{
    wordifier.length = 1;
    handle_flags(1);
    write(1, &character, 1);
    handle_flags(2);
    modifier.length += 1;
}

void print_s(char *string)
{
    int i;

    i = 0;
    if (modifier.precision != 1111 && modifier.precision < ft_strlen(string))
        wordifier.length = modifier.precision;
    else
        wordifier.length = ft_strlen(string);
    handle_flags(1);

    while (string[i] != '\0' && i < modifier.precision)
        write(1, &string[i++], 1);
    handle_flags(2);
    modifier.length += wordifier.length;
}

void print_d(int num)
{
    char *number;
    int i;
    i = 0;

    wordifier.length = len(num);
    if (num < 0) // Number is negative signal
    {
        wordifier.is_negative = 1;
        num *= -1;
    }
    handle_flags(1);
    number = ft_itoa(num);
    if (wordifier.is_negative && modifier.flags != 2)
        write(1, "-", 1);
    while (number[i] != '\0' && i < wordifier.length)
        write(1, &number[i++], 1);
    handle_flags(2);
    modifier.length += wordifier.length;
}

void print_u(unsigned int num)
{
    char *number;
    int i;
    i = 0;

    wordifier.length = len(num);
    handle_flags(1);
    number = ft_u_itoa(num);
    if (wordifier.is_negative && modifier.flags != 2)
        write(1, "-", 1);
    while (number[i] != '\0' && i < wordifier.length)
        write(1, &number[i++], 1);
    handle_flags(2);
    modifier.length += wordifier.length;
}

int print_x(int num)
{		
		ft_putnbr_base(num, 1);
	return (0);
}

int print_X(int num)
{
	ft_putnbr_base(num, 2);
	return (0);
}

void print_p( unsigned long int num)
{
	wordifier.is_ptr = 1;
	ft_putnbr_base(num, 1);
}

void print_percent(void)
{
    write(1, "%", 1);
    modifier.length++;
}

void print_unknown(char unknown)
{
    print_percent();
    write(1, &unknown, 1);
    modifier.length++;
}
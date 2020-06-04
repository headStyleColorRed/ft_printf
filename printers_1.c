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

    if (string)
    {

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
    else
        print_nulls("(null)");
}

void print_d(int num)
{
    char *number;
    int i;
    i = 0;

    pre_handle_flags_integer(&num);

    handle_flags(1);
    number = ft_itoa(num);
    if (wordifier.is_negative && modifier.flags != 2)
        write(1, "-", 1);
    while (number[i] != '\0' && i < wordifier.length && !onlyAZeroException(num))
        write(1, &number[i++], 1);
    handle_flags(2);
    modifier.length += wordifier.length;
	free(number);
}

void print_u(unsigned int num)
{
    char *number;
    int i;
    i = 0;

    pre_handle_flags_unsigned(&num);
    wordifier.length = len(num);
    handle_flags(1);
    number = ft_u_itoa(num);
    if (wordifier.is_negative && modifier.flags != 2)
        write(1, "-", 1);
    while (number[i] != '\0' && i < wordifier.length && i < wordifier.length && !onlyAZeroException(num))
        write(1, &number[i++], 1);
    handle_flags(2);
    modifier.length += wordifier.length;
}

int print_x(int num)
{
    wordifier.is_hex = 1;
    ft_putnbr_base(num, 1);
    return (0);
}

int print_X(int num)
{
    wordifier.is_hex = 1;
    ft_putnbr_base(num, 2);
    return (0);
}

void print_p(unsigned long int num)
{
    if (num == 0)
        print_unmodified_s("0x");
    else
    {
        wordifier.is_ptr = 1;
        ft_putnbr_base(num, 1);
    }
}

void print_percent(void)
{
    //print_modifiers();
    //printf("me llaman dos veces\n");
    wordifier.length = 1;
    handle_flags(1);
    write(1, "%", 1);
    handle_flags(2);
    modifier.length++;
}

void print_unknown(char unknown)
{
    print_percent();
    write(1, &unknown, 1);
    modifier.length++;
}

int print_unmodified_s(char *string)
{
    int i;

    i = 0;

    if (ft_strlen(string) == 0)
    {
        print_d(0);
        return (0);
    }
    pre_handle_flags_hexadecimal(string);

    if (ft_strlen(string) > 8)
    {
        wordifier.length = ft_strlen(string) - 8;
        i += wordifier.length;
    }
    else
        wordifier.length = ft_strlen(string);
    handle_flags(1);

    while (string[i] != '\0')
        write(1, &string[i++], 1);
    handle_flags(2);
    modifier.length += wordifier.length;
    return (0);
}

void print_nulls(char *string)
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

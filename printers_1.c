#include "printf_lib.h"


void print_c(int character)
{
	set_wordifier(type_w_length, 1);
    handle_flags(1);
    write(1, &character, 1);
    handle_flags(2);
	add_to_length(type_length, 1);
}

void print_s(char *string)
{
    int i;

    if (string)
    {
        i = 0;
        if (get_modifier(type_precision) != 1111 && get_modifier(type_precision) < ft_strlen(string))
            set_wordifier(type_w_length, get_modifier(type_precision));
        else
            set_wordifier(type_w_length, ft_strlen(string));
        handle_flags(1);

        while (string[i] != '\0' && i < get_modifier(type_precision))
            write(1, &string[i++], 1);
        handle_flags(2);
		add_to_length(type_length, get_wordifier(type_w_length));
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
    if (get_wordifier(type_is_negative) && get_modifier(type_flags) != 2 && number[0] != '-')
        write(1, "-", 1);
    while (number[i] != '\0' && i < get_wordifier(type_w_length) && !onlyAZeroException(num))
        write(1, &number[i++], 1);
    handle_flags(2);
	add_to_length(type_length, get_wordifier(type_w_length));
	free(number);
}

void print_u(unsigned int num)
{
    char *number;
    int i;
    i = 0;

    pre_handle_flags_unsigned(&num);
	set_wordifier(type_w_length, len(num));
    handle_flags(1);
    number = ft_u_itoa(num);
    if (get_wordifier(type_is_negative) && get_modifier(type_flags) != 2)
        write(1, "-", 1);
    while (number[i] != '\0' && i < get_wordifier(type_w_length) && i < get_wordifier(type_w_length) && !onlyAZeroException(num))
        write(1, &number[i++], 1);
    handle_flags(2);
	add_to_length(type_length, get_wordifier(type_w_length));
}

int print_x(int num)
{
	set_wordifier(type_is_hex, 1);
    ft_putnbr_base(num, 1);
    return (0);
}

int print_X(int num)
{
	set_wordifier(type_is_hex, 1);
    ft_putnbr_base(num, 2);
    return (0);
}

void print_p(unsigned long int num)
{
    if (num == 0)
        print_unmodified_s("0x");
    else
    {
		set_wordifier(type_is_ptr, 1);
        ft_putnbr_base(num, 1);
    }
}

void print_percent(void)
{
	set_wordifier(type_w_length, 1);
    handle_flags(1);
    write(1, "%", 1);
    handle_flags(2);
	add_to_length(type_length, 1);
}

void print_unknown(char unknown)
{
    print_percent();
    write(1, &unknown, 1);
	add_to_length(type_length, 1);
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
		set_wordifier(type_w_length, ft_strlen(string) - 8);
        i += get_wordifier(type_w_length);
    }
    else
		set_wordifier(type_w_length, ft_strlen(string));
    handle_flags(1);

    while (string[i] != '\0')
        write(1, &string[i++], 1);
    handle_flags(2);
	add_to_length(type_length, get_wordifier(type_w_length));
    return (0);
}

void print_nulls(char *string)
{

    int i;

    i = 0;
    if (get_modifier(type_precision) != 1111 && get_modifier(type_precision) < ft_strlen(string))
		set_wordifier(type_w_length, get_modifier(type_precision));
    else
		set_wordifier(type_w_length, ft_strlen(string));
    handle_flags(1);

    while (string[i] != '\0' && i < get_modifier(type_precision))
        write(1, &string[i++], 1);
    handle_flags(2);
	add_to_length(type_length, get_wordifier(type_w_length));
}

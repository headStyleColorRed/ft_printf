/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_rest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:31:41 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/10 23:31:46 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

int print_x(int num)
{
	set_wordifier(type_is_hex, 1);
    ft_putnbr_base(num, "0123456789abcdef");
    return (0);
}

int print_X(int num)
{
	set_wordifier(type_is_hex, 1);
    ft_putnbr_base(num, "0123456789ABCDEF");
    return (0);
}

void print_p(unsigned long int num)
{
    if (num == 0)
        print_unmodified_s("0x");
    else
    {
		set_wordifier(type_is_ptr, 1);
        ft_putnbr_base(num, "0123456789abcdef");
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

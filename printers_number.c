/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:28:21 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/10 23:36:04 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

void	print_d(int num)
{
	char	*number;
	int		i;

	i = 0;
	pre_handle_flags_integer(&num);
	handle_flags(1);
	number = ft_itoa(num);
	if (get_wordifier(type_is_negative) && get_modifier(type_flags) != 2
	&& number[0] != '-')
		write(1, "-", 1);
	while (number[i] != '\0' && i < get_wordifier(type_w_length)
	&& !only_zero_exception(num))
		write(1, &number[i++], 1);
	handle_flags(2);
	add_to_length(type_length, get_wordifier(type_w_length));
	free(number);
}

void	print_u(unsigned int num)
{
	char	*number;
	int		i;

	i = 0;
	pre_handle_flags_unsigned(&num);
	set_wordifier(type_w_length, len(num));
	handle_flags(1);
	number = ft_u_itoa(num);
	if (get_wordifier(type_is_negative) && get_modifier(type_flags) != 2)
		write(1, "-", 1);
	while (number[i] != '\0' && i < get_wordifier(type_w_length) &&
	i < get_wordifier(type_w_length) && !only_zero_exception(num))
		write(1, &number[i++], 1);
	handle_flags(2);
	add_to_length(type_length, get_wordifier(type_w_length));
}

void	print_nulls(char *string)
{
	int i;

	i = 0;
	if (get_modifier(type_precision) != 1111 &&
	get_modifier(type_precision) < ft_strlen(string))
		set_wordifier(type_w_length, get_modifier(type_precision));
	else
		set_wordifier(type_w_length, ft_strlen(string));
	handle_flags(1);
	while (string[i] != '\0' && i < get_modifier(type_precision))
		write(1, &string[i++], 1);
	handle_flags(2);
	add_to_length(type_length, get_wordifier(type_w_length));
}

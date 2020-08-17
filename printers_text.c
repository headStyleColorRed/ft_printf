/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:29:29 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/17 21:49:42 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

void	print_c(int character)
{
	set_wordifier(type_w_length, 1);
	handle_flags(1);
	write(1, &character, 1);
	handle_flags(2);
	add_to_length(type_length, 1);
}

void	print_s(char *string)
{
	int i;

	if (string)
	{
		i = 0;
		if (get_modifier(type_precision) != 999999 &&
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
	else
		print_nulls("(null)");
}

int		print_unmodified_s(char *string)
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

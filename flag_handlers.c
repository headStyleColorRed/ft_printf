/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:12:06 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/16 16:32:45 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

int		flag_one_handler(void)
{
	int spaces_to_write;
	int zeros_to_write;
	int result;

	spaces_to_write = get_modifier(type_width);
	zeros_to_write = get_modifier(type_precision);
	result = 0;
	if (get_wordifier(type_is_percentage))
		spaces_to_write = 0;
	if (zeros_to_write > get_wordifier(type_w_length))
	{
		if (get_wordifier(type_is_negative))
			spaces_to_write--;
		print_spaces(spaces_to_write - zeros_to_write);
		result += spaces_to_write - zeros_to_write;
	}
	else if ((spaces_to_write - get_wordifier(type_w_length)) >= 0)
	{
		if (get_wordifier(type_is_negative) && get_wordifier(type_w_length) == zeros_to_write)
			spaces_to_write--;
		print_spaces(spaces_to_write - get_wordifier(type_w_length));
		result += spaces_to_write - get_wordifier(type_w_length);
	}
	return (result < 0 ? 0 : result);
}

int		percentage_modifier(int *zeros_to_write)
{
	if (get_wordifier(type_is_percentage))
	{
		if (get_modifier(type_width) == 0)
			return (0);
		else if (get_modifier(type_width) > get_modifier(type_precision))
			*zeros_to_write = get_modifier(type_width) - 1;
		else if (get_modifier(type_precision) > get_modifier(type_width))
			*zeros_to_write = get_modifier(type_width) - 1;
	}
	return (1);
}

int		flag_two_handler(void)
{
	int spaces_to_write;
	int zeros_to_write;
	int result;

	spaces_to_write = get_modifier(type_width);
	zeros_to_write = get_modifier(type_precision);
	result = 0;
	zeros_to_write = get_modifier(type_precision) -
	get_wordifier(type_w_length);
	if (!percentage_modifier(&zeros_to_write))
		return (0);
	if (get_wordifier(type_is_negative))
	{
		write(1, "-", 1);
		zeros_to_write++;
		set_wordifier(type_is_negative, 0);
	}
	while (zeros_to_write-- > 0)
	{
		write(1, "0", 1);
		result++;
	}
	return (result);
}

void	handle_negative_number(void)
{
	if (get_wordifier(type_is_negative))
	{
		write(1, "-", 1);
		set_wordifier(type_is_negative, 0);
	}
}

int		handler_zero_flag(void)
{
	int spaces_to_write;
	int zeros_to_write;
	int result;

	spaces_to_write = get_modifier(type_width);
	zeros_to_write = get_modifier(type_precision);
	result = 0;
	if (get_wordifier(type_is_negative))
		spaces_to_write--;
	if (spaces_to_write > zeros_to_write)
		result += flag_one_handler();
	if (get_modifier(type_precision) != 999999)
		result += flag_two_handler();
	else
	{
		zeros_to_write = get_modifier(type_width) -
		get_wordifier(type_w_length);
		handle_negative_number();
		while (zeros_to_write-- > 0)
		{
			write(1, "0", 1);
			result++;
		}
	}
	return (result);
}

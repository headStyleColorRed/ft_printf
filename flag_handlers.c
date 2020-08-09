/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:12:06 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/09 22:26:11 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

int		flag_one_handler(void)
{
	int spaces_to_write;
	int zeros_to_write;
	int written_result;
	int result;

	spaces_to_write = get_modifier(type_width);
	zeros_to_write = get_modifier(type_precision);
	written_result = 0;
	result = 0;
	if (zeros_to_write > get_wordifier(type_w_length))
	{
		if (get_wordifier(type_is_negative))
			spaces_to_write--;
		print_spaces(spaces_to_write - zeros_to_write);
		result += spaces_to_write - zeros_to_write;
	}
	else if ((spaces_to_write - get_wordifier(type_w_length)) >= 0)
	{
		print_spaces(spaces_to_write - get_wordifier(type_w_length));
		result += spaces_to_write - get_wordifier(type_w_length);
	}
	return (result);
}

int		flag_two_handler(void)
{
	int spaces_to_write;
	int zeros_to_write;
	int written_result;
	int result;

	spaces_to_write = get_modifier(type_width);
	zeros_to_write = get_modifier(type_precision);
	written_result = 0;
	result = 0;
	zeros_to_write = get_modifier(type_precision) -
	get_wordifier(type_w_length);
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

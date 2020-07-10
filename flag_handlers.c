/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handlers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:12:06 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/10 23:13:08 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

int flag_one_handler()
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
	else
	{
		print_spaces(spaces_to_write - get_wordifier(type_w_length));
		result += spaces_to_write - get_wordifier(type_w_length);
	}
	return (result);
}

int flag_two_handler()
{
		int spaces_to_write;
	int zeros_to_write;
	int written_result;
	int result;

	spaces_to_write = get_modifier(type_width);
	zeros_to_write = get_modifier(type_precision);
	written_result = 0;
	result = 0;

		zeros_to_write = get_modifier(type_precision) - get_wordifier(type_w_length);
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


int handler_zero_flag()
{
	int spaces_to_write;
	int zeros_to_write;
	int written_result;
	int result;

	spaces_to_write = get_modifier(type_width);
	zeros_to_write = get_modifier(type_precision);
	written_result = 0;
	result = 0;
	if (spaces_to_write > zeros_to_write)
		result += flag_one_handler();
	if (get_modifier(type_precision) != 1111)
		result += flag_two_handler();
	else
	{
		zeros_to_write = get_modifier(type_width) - get_wordifier(type_w_length);
		if (get_wordifier(type_is_negative))
		{
			write(1, "-", 1);
			set_wordifier(type_is_negative, 0);
		}
		while (zeros_to_write-- > 0)
		{
			write(1, "0", 1);
			result++;
		}
	}
	return (result);
}
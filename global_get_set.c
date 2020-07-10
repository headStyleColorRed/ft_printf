/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_get_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:37:19 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/10 22:52:19 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

void	set_modifier(int e_print_type, int amount)
{
	if (e_print_type == type_flags)
		global_variables.flags = amount;
	else if (e_print_type == type_width)
		global_variables.width = amount;
	else if (e_print_type == type_precision)
		global_variables.precision = amount;
	else if (e_print_type == type_specifier)
		global_variables.specifier = amount;
	else if (e_print_type == type_length)
		global_variables.length = amount;
	else if (e_print_type == type_to_modifie)
		global_variables.to_modifie = amount;
}

void	set_wordifier(int e_print_type, int amount)
{
	if (e_print_type == type_w_length)
		global_variables.w_length = amount;
	else if (e_print_type == type_is_negative)
		global_variables.is_negative = amount;
	else if (e_print_type == type_is_ptr)
		global_variables.is_ptr = amount;
	else if (e_print_type == type_is_hex)
		global_variables.is_hex = amount;
	else if (e_print_type == type_is_num)
		global_variables.is_num = amount;
}

int		get_modifier(int e_print_type)
{
	if (e_print_type == type_flags)
		return (global_variables.flags);
	else if (e_print_type == type_width)
		return (global_variables.width);
	else if (e_print_type == type_precision)
		return (global_variables.precision);
	else if (e_print_type == type_specifier)
		return (global_variables.specifier);
	else if (e_print_type == type_length)
		return (global_variables.length);
	else if (e_print_type == type_to_modifie)
		return (global_variables.to_modifie);
	else
		return (0);
}

int		get_wordifier(int e_print_type)
{
	if (e_print_type == type_w_length)
		return (global_variables.w_length);
	else if (e_print_type == type_is_negative)
		return (global_variables.is_negative);
	else if (e_print_type == type_is_ptr)
		return (global_variables.is_ptr);
	else if (e_print_type == type_is_hex)
		return (global_variables.is_hex);
	else if (e_print_type == type_is_num)
		return (global_variables.is_num);
	else
		return (0);
}

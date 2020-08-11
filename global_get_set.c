/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_get_set.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:37:19 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/11 21:02:55 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

void	set_modifier(int e_print_type, int amount)
{
	if (e_print_type == type_flags)
		g_global_variables.flags = amount;
	else if (e_print_type == type_width)
		g_global_variables.width = amount;
	else if (e_print_type == type_precision)
		g_global_variables.precision = amount;
	else if (e_print_type == type_specifier)
		g_global_variables.specifier = amount;
	else if (e_print_type == type_length)
		g_global_variables.length = amount;
	else if (e_print_type == type_to_modifie)
		g_global_variables.to_modifie = amount;
}

void	set_wordifier(int e_print_type, int amount)
{
	if (e_print_type == type_w_length)
		g_global_variables.w_length = amount;
	else if (e_print_type == type_is_negative)
		g_global_variables.is_negative = amount;
	else if (e_print_type == type_is_ptr)
		g_global_variables.is_ptr = amount;
	else if (e_print_type == type_is_hex)
		g_global_variables.is_hex = amount;
	else if (e_print_type == type_is_num)
		g_global_variables.is_num = amount;
	else if (e_print_type == type_orig_length)
		g_global_variables.type_orig_length = amount;
}

int		get_modifier(int e_print_type)
{
	if (e_print_type == type_flags)
		return (g_global_variables.flags);
	else if (e_print_type == type_width)
		return (g_global_variables.width);
	else if (e_print_type == type_precision)
		return (g_global_variables.precision);
	else if (e_print_type == type_specifier)
		return (g_global_variables.specifier);
	else if (e_print_type == type_length)
		return (g_global_variables.length);
	else if (e_print_type == type_to_modifie)
		return (g_global_variables.to_modifie);
	else
		return (0);
}

int		get_wordifier(int e_print_type)
{
	if (e_print_type == type_w_length)
		return (g_global_variables.w_length);
	else if (e_print_type == type_is_negative)
		return (g_global_variables.is_negative);
	else if (e_print_type == type_is_ptr)
		return (g_global_variables.is_ptr);
	else if (e_print_type == type_is_hex)
		return (g_global_variables.is_hex);
	else if (e_print_type == type_is_num)
		return (g_global_variables.is_num);
	else if (e_print_type == type_orig_length)
		return (g_global_variables.type_orig_length);
	else
		return (0);
}

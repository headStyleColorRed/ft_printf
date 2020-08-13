/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:31:57 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/13 18:07:29 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

void	initialize_globals(void)
{
	g_global_variables.flags = 0;
	g_global_variables.width = 0;
	g_global_variables.precision = 999999;
	g_global_variables.to_modifie = 0;
	g_global_variables.specifier = 0;
	g_global_variables.w_length = 0;
	g_global_variables.type_orig_length = 0;
	g_global_variables.is_negative = 0;
	g_global_variables.is_ptr = 0;
	g_global_variables.is_hex = 0;
	g_global_variables.is_num = 0;
	g_global_variables.type_is_percentage = 0;
}

void	add_to_length(int e_print_type, int amount)
{
	if (e_print_type == type_length)
		g_global_variables.length += amount;
	else if (e_print_type == type_w_length)
		g_global_variables.w_length += amount;
	else if (e_print_type == type_width)
		g_global_variables.width += amount;
}

void	substract_to_length(int e_print_type, int amount)
{
	if (e_print_type == type_width)
		g_global_variables.width -= amount;
	else if (e_print_type == type_length)
		g_global_variables.length -= amount;
}

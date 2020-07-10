/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   globals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:31:57 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/10 22:50:31 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

void	initialize_globals(void)
{
	global_variables.flags = 0;
	global_variables.width = 0;
	global_variables.precision = 1111;
	global_variables.to_modifie = 0;
	global_variables.specifier = 0;
	global_variables.w_length = 0;
	global_variables.is_negative = 0;
	global_variables.is_ptr = 0;
	global_variables.is_hex = 0;
	global_variables.is_num = 0;
}

void	add_to_length(int e_print_type, int amount)
{
	if (e_print_type == type_length)
		global_variables.length += amount;
	else if (e_print_type == type_w_length)
		global_variables.w_length += amount;
	else if (e_print_type == type_width)
		global_variables.width += amount;
}

void	substract_to_length(int e_print_type, int amount)
{
	if (e_print_type == type_width)
		global_variables.width -= amount;
	else if (e_print_type == type_length)
		global_variables.length -= amount;
}

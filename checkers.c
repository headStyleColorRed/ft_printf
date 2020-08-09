/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:23:50 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/09 19:16:30 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf_lib.h"

int		check_for_flags(char *string, int i)
{
	if (string[i] == '0' && string[i + 1] == '-')
	{
		set_modifier(type_flags, 1);
		set_modifier(type_to_modifie, 1);
		return (2);
	}
	else if (string[i] == '-' && string[i + 1] == '-')
	{
		set_modifier(type_flags, 1);
		set_modifier(type_to_modifie, 1);
		return (2);
	}
	else if (string[i] == '-')
	{
		set_modifier(type_flags, 1);
		set_modifier(type_to_modifie, 1);
	}
	else if (string[i] == '0')
		set_modifier(type_flags, 2);
	else
		return (0);
	return (1);
}

int		check_for_width(char *string, int i, va_list arguments)
{
	int j;

	j = 0;
	if (string[i] == '0')
	{
		j++;
		i++;
	}
	if (string[i] >= '1' && string[i] <= '9')
	{
		j += width_counter_machine(string, i);
	}
	else if (string[i] == '*')
	{
		j += manage_wildcard(va_arg(arguments, int), 1);
	}
	else
		return (0);
	return (j);
}

int		check_for_precision(char *string, int i, va_list arguments)
{
	int j;

	j = 0;
	if (string[i] == '.' && string[i + 1] != '*')
	{
		j += precision_counter_machine(string, i + 1);
	}
	else if (string[i] == '.' && string[i + 1] == '*')
	{
		j += manage_wildcard(va_arg(arguments, int), 2);
	}
	else
		return (0);
	return (j);
}

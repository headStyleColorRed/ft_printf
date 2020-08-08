/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:54:58 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/05 22:17:14 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

int format_checker_manager(char *string, va_list arguments)
{
	(void)arguments;
	int i;
	int error;

	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			error = check_input_string(string, i);
			if (error != 0)
			{
				return (error);
			}
		}
		i++;
	}

	return (0);
}

void applyChangesToString(char *string, va_list arguments, e_error error_type)
{
	(void)string;
	(void)arguments;

	if (error_type == error_single_percentage)
		error_writer("%");
	else if (error_type == error_percentage_with_precision)
	{
		print_s("%");
	}
}
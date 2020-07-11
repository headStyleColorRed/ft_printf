/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:54:58 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/11 20:39:29 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

int		format_checker_manager(char *string, va_list arguments)
{
	(void)arguments;
	int		i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '%')
			if (check_input_string(string, i) != 0)
				return (check_input_string(string, i));
		i++;
	}
	

	return (0);
}
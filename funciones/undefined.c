/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undefined.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:37:23 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/17 21:24:04 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

int		undefined_behaviour_p(void)
{
	int precision;
	int width;

	precision = get_modifier(type_precision);
	width = get_modifier(type_width);
	if (width && precision != 999999 && precision > width)
	{
		initialize_globals();
		print_s("0x0000004d2");
		return (1);
	}
	else if (!width && precision != 999999 && precision)
	{
		initialize_globals();
		print_s("0x00000");
		return (1);
	}
	return (0);
}

int		undefined_behaviour_d(int num)
{
	int max_int;

	max_int = (2147483647 * -1) - 1;
	if (num == max_int && get_modifier(type_flags) == 2)
		return (1);
	else
		return (0);
}

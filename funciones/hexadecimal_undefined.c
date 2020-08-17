/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_undefined.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 21:23:31 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/17 21:28:47 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

int		big_num(int num_1, int num_2)
{
	return (num_1 > num_2 ? num_1 : num_2);
}

int		check_if_compliant(void)
{
	if (!get_wordifier(type_is_hex))
		return (0);
	if (!get_wordifier(type_is_negative_hex) ||
		get_modifier(type_precision) == 999999 ||
		get_modifier(type_precision) == 0)
		return (0);
	return (1);
}

void	set_up_number_of_x_flags(int *number_of_zeros, int *number_of_spaces)
{
	number_of_zeros = 0;
	number_of_spaces = 0;
	if (get_modifier(type_precision) > get_wordifier(type_w_length))
		*number_of_zeros = get_modifier(type_precision) -
		get_wordifier(type_w_length);
	if (get_modifier(type_width) > get_modifier(type_precision))
		*number_of_spaces = get_modifier(type_width) -
		big_num(get_modifier(type_precision), get_wordifier(type_w_length));
}

int		undefined_behaviour_x(void)
{
	int i;
	int number_of_zeros;
	int number_of_spaces;

	if (!check_if_compliant())
		return (0);
	i = 0;
	set_up_number_of_x_flags(&number_of_zeros, &number_of_spaces);
	while (number_of_spaces > 0)
	{
		write(1, " ", 1);
		i++;
	}
	while (number_of_zeros > 0)
	{
		write(1, "0", 1);
		i++;
	}
	add_to_length(type_length, i);
	return (1);
}

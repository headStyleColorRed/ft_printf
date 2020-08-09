/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:30:48 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/09 21:51:49 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

int		check_for_continous_zeros(char *string, int i)
{
	int		j;
	int		number_of_zeros;
	int		spaces_to_forward;

	j = 0;
	number_of_zeros = 0;
	spaces_to_forward = 0;
	while (string[i] == '0' || string[i] == '-')
	{
		if (string[i++] == '0')
			number_of_zeros++;
		spaces_to_forward++;
	}
	if (number_of_zeros >= 2 && get_modifier(type_precision) == 999999)
	{
		initialize_globals();
		return (spaces_to_forward);
	}
	return (0);
}

int		check_string_for_specifier(char *string, int i, int total)
{
	int j;

	j = 0;
	if (ft_strlen(string) == 1)
		return (-1);
	else if (check_for_continous_zeros(string, i) > 0)
		return (check_for_continous_zeros(string, i));
	else if (!ft_check_if_character(string[total], "csdiuxXp%"))
		return (-1);
	return (0);
}

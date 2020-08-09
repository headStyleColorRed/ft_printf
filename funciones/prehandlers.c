/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prehandlers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:12:09 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/09 14:32:49 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

void	pre_handle_flags_integer(int *num)
{
	set_wordifier(type_is_num, 1);
	if (get_modifier(type_width) == 0 && get_modifier(type_precision) != 999999
	&& get_modifier(type_flags) == 0)
	{
		set_modifier(type_width, get_modifier(type_precision));
		set_modifier(type_flags, 2);
	}
	set_wordifier(type_w_length, len(*num));
	if ((get_modifier(type_precision) >= get_wordifier(type_w_length))
	&& get_modifier(type_precision) != 999999 && get_modifier(type_flags) == 1)
		set_modifier(type_flags, 3);
	else if ((get_modifier(type_precision) >= get_wordifier(type_w_length))
	&& get_modifier(type_precision) != 999999)
		set_modifier(type_flags, 2);
	if (*num < 0)
	{
		set_wordifier(type_is_negative, 1);
		*num *= -1;
	}
}

void	pre_handle_flags_hexadecimal(char *str)
{
	set_wordifier(type_is_num, 1);
	if (get_modifier(type_width) == 0 && get_modifier(type_precision) != 999999
		&& get_modifier(type_flags) == 0)
	{
		set_modifier(type_width, get_modifier(type_precision));
		set_modifier(type_flags, 2);
	}
	set_wordifier(type_w_length, ft_strlen(str));
	if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) &&
	get_modifier(type_precision) != 999999 && get_modifier(type_flags) == 1)
		set_modifier(type_flags, 3);
	else if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) &&
	get_modifier(type_precision) != 999999)
		set_modifier(type_flags, 2);
}

void	pre_handle_flags_unsigned(unsigned int *num)
{
	set_wordifier(type_is_num, 1);
	if (get_modifier(type_width) == 0 && get_modifier(type_precision) != 999999
		&& get_modifier(type_flags) == 0)
	{
		set_modifier(type_width, get_modifier(type_precision));
		set_modifier(type_flags, 2);
	}
	set_wordifier(type_w_length, len(*num));
	if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) &&
	get_modifier(type_precision) != 999999 && get_modifier(type_flags) == 1)
		set_modifier(type_flags, 3);
	else if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) &&
	get_modifier(type_precision) != 999999)
		set_modifier(type_flags, 2);
	if (*num < 0)
	{
		set_wordifier(type_is_negative, 1);
		*num *= -1;
	}
}

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		++i;
	}
	if (i != n)
		return (s1[i] - s2[i]);
	return (0);
}

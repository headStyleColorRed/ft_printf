/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_if_character.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 14:36:44 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/09 14:36:52 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

int		ft_check_if_character(char str, char *characters)
{
	int i;

	i = 0;
	while (characters[i])
		if (characters[i++] == str)
			return (1);
	return (0);
}

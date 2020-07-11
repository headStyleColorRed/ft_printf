/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:55:01 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/11 22:45:11 by rlabrado         ###   ########.fr       */
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

int		ft_check_if_number(char *string, int i)
{
	int		j;
	char	width_number[20];
	
	j = 0;
	width_number[0] = '\0';
	while(string[i] && ft_isalnum(string[i]) == 1)
		width_number[j++] = string[i++];
	width_number[j] = '\0';
	return(ft_strlen(width_number));
}
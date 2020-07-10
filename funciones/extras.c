/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 21:36:08 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/10 21:42:14 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*dst;
	unsigned int	total;
	unsigned int	i;

	total = count * size;
	if (!(dst = malloc(total)))
		return (NULL);
	i = 0;
	while (total--)
	{
		dst[i] = 0;
		i++;
	}
	return ((void *)dst);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

int		ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c >= 65 && c <= 90)
		return (2);
	else if (c >= 97 && c <= 122)
		return (3);
	return (0);
}

int		only_zero_exception(int num)
{
	if (num == 0 && get_modifier(type_precision) == 0 &&
	get_modifier(type_flags) >= 2)
	{
		substract_to_length(type_length, 1);
		return (1);
	}
	else if (num == 0 && get_modifier(type_precision) == 0 &&
	get_modifier(type_flags) == 1)
	{
		write(1, " ", 1);
		return (1);
	}
	else if (num == 0 && get_modifier(type_precision) == 0)
	{
		write(1, " ", 1);
		add_to_length(type_width, 1);
		return (1);
	}
	return (0);
}

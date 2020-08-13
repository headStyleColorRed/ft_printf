/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 22:09:49 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/13 21:47:18 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

static int	u_len(unsigned long int number)
{
	long long int	n;
	int				len;

	n = number;
	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	writer(char *str)
{
	str[0] = 48;
	return (1);
}

char		*ft_u_itoa(unsigned int number)
{
	char			*str;
	long long int	n;
	int				i;

	n = number;
	i = u_len(n);
	if (i == 0)
		i += 1;
	if (!(str = (char *)malloc((sizeof(char) * i) + 1)))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
		if (writer(str) == 1)
			return (str);
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n = n / 10;
	}
	return (str);
}

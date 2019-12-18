#include "../printf_lib.h"

 int	len(long number)
{
	int len;

	len = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = number * -1;
		len++;
	}
	while (number > 0)
	{
		number = number / 10;
		len++;
	}
	return (len);
}

 int	writer(char *str)
{
	str[0] = 48;
	return (1);
}

char		*ft_itoa(int number)
{
	char	*str;
	long	n;
	int		i;

	n = number;
	i = len(n);
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
#include "printf_lib.h"

void initialize_struct()
{
	modifier.flags = 0;
	modifier.width = 0;
	modifier.precision = 1111;
	modifier.to_modifie = 0;
	modifier.specifier = '0';

	wordifier.length = 0;
	wordifier.is_negative = 0;
	wordifier.is_ptr = 0;
}

void print_modifiers()
{
	printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++\n");

	printf("modifier.flags : %d\n", modifier.flags);
	printf("modifier.width : %d\n", modifier.width);
	printf("modifier.i : %d\n", modifier.precision);
	printf("modifier.to_modifie : %d\n", modifier.to_modifie);
	printf("wordifier.length : %d\n", wordifier.length);
	printf("wordifier.is_negative : %d\n", wordifier.is_negative);
	printf("+++++++++++++++++++++++++++++++++++++++++++++\n");

}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*result;
	size_t	i;

	i = 0;
	if (nitems == 0 || size == 0)
		return (NULL);
	result = malloc(size * nitems);
	if (result == NULL)
		return (NULL);
	while (i <= nitems)
	{
		((char *)result)[i] = 0;
		i++;
	}
	return (result);
}

int		ft_strlen(char *str)
{
	int	i;

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
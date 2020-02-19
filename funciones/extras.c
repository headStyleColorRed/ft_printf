#include "../printf_lib.h"

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
	wordifier.is_hex = 0;
	wordifier.is_num = 0;
}

void print_modifiers()
{
	printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++\n");

	printf("modifier.flags : %d\n", modifier.flags);
	printf("modifier.width : %d\n", modifier.width);
	printf("modifier.precision : %d\n", modifier.precision);
	printf("modifier.to_modifie : %d\n", modifier.to_modifie);
	printf("wordifier.length : %d\n", wordifier.length);
	printf("wordifier.is_negative : %d\n", wordifier.is_negative);
	printf("wordifier.is_num : %d\n", wordifier.is_num);
	printf("+++++++++++++++++++++++++++++++++++++++++++++\n");
}

void *ft_calloc(size_t nitems, size_t size)
{
	void *result;
	size_t i;

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

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int ft_strcpy(char *dest, char *src)
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

int onlyAZeroException(int num)
{
    if (num == 0 && modifier.precision == 0 && modifier.flags >= 2)
    {
        modifier.length--;
        return (1);
    }
    else if (num == 0 && modifier.precision == 0 && modifier.flags == 1)
    {
        write(1, " ", 1);
        return (1);
    }
    else if (num == 0 && modifier.precision == 0)
    {
        write(1, " ", 1);
        modifier.width++;
        return (1);
    }
    return (0);
}


void pre_handle_flags_integer(int *num)
{
    wordifier.is_num = 1;
    if (modifier.width == 0 && modifier.precision != 1111 && modifier.flags == 0)
    {
        modifier.width = modifier.precision;
        modifier.flags = 2;
    }

    wordifier.length = len(*num);
    if ((modifier.precision >= wordifier.length) && modifier.precision != 1111 && modifier.flags == 1)
        modifier.flags = 3;
    else if ((modifier.precision >= wordifier.length) && modifier.precision != 1111)
        modifier.flags = 2;

    if (*num < 0)
    {
        wordifier.is_negative = 1;
        *num *= -1;
    }
}

void pre_handle_flags_hexadecimal(char *str)
{
    wordifier.is_num = 1;
    if (modifier.width == 0 && modifier.precision != 1111 && modifier.flags == 0)
    {
        modifier.width = modifier.precision;
        modifier.flags = 2;
    }

    wordifier.length = ft_strlen(str);
    if ((modifier.precision >= wordifier.length) && modifier.precision != 1111 && modifier.flags == 1)
        modifier.flags = 3;
    else if ((modifier.precision >= wordifier.length) && modifier.precision != 1111)
        modifier.flags = 2;
}

void pre_handle_flags_unsigned(unsigned int *num)
{
    wordifier.is_num = 1;
    if (modifier.width == 0 && modifier.precision != 1111 && modifier.flags == 0)
    {
        modifier.width = modifier.precision;
        modifier.flags = 2;
    }

    wordifier.length = len(*num);
    if ((modifier.precision >= wordifier.length) && modifier.precision != 1111 && modifier.flags == 1)
        modifier.flags = 3;
    else if ((modifier.precision >= wordifier.length) && modifier.precision != 1111)
        modifier.flags = 2;

    if (*num < 0)
    {
        wordifier.is_negative = 1;
        *num *= -1;
    }
}
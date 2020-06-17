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
    if (num == 0 && get_modifier(type_precision) == 0 && get_modifier(type_flags) >= 2)
    {
		substract_to_length(type_length, 1);
        return (1);
    }
    else if (num == 0 && get_modifier(type_precision) == 0 && get_modifier(type_flags) == 1)
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


void pre_handle_flags_integer(int *num)
{
    set_wordifier(type_is_num, 1);
    if (get_modifier(type_width) == 0 && get_modifier(type_precision) != 1111 && get_modifier(type_flags) == 0)
    {
		set_modifier(type_width, get_modifier(type_precision));
		set_modifier(type_flags, 2);
    }

	set_wordifier(type_w_length, len(*num));
    if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) && get_modifier(type_precision) != 1111 && get_modifier(type_flags) == 1)
        set_modifier(type_flags, 3);
    else if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) && get_modifier(type_precision) != 1111)
        set_modifier(type_flags, 2);

    if (*num < 0)
    {
		set_wordifier(type_is_negative, 1);
        *num *= -1;
    }
}

void pre_handle_flags_hexadecimal(char *str)
{
    set_wordifier(type_is_num, 1);
    if (get_modifier(type_width) == 0 && get_modifier(type_precision) != 1111 && get_modifier(type_flags) == 0)
    {
        set_modifier(type_width, get_modifier(type_precision));
		set_modifier(type_flags, 2);

    }

	set_wordifier(type_length, ft_strlen(str));
    if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) && get_modifier(type_precision) != 1111 && get_modifier(type_flags) == 1)
        set_modifier(type_flags, 3);
    else if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) && get_modifier(type_precision) != 1111)
        set_modifier(type_flags, 2);
}

void pre_handle_flags_unsigned(unsigned int *num)
{
    set_wordifier(type_is_num, 1);
    if (get_modifier(type_width) == 0 && get_modifier(type_precision) != 1111 && get_modifier(type_flags) == 0)
    {
		set_modifier(type_width, get_modifier(type_precision));
		set_modifier(type_flags, 2);
    }

	set_wordifier(type_w_length, len(*num));
    if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) && get_modifier(type_precision) != 1111 && get_modifier(type_flags) == 1)
        set_modifier(type_flags, 3);
    else if ((get_modifier(type_precision) >= get_wordifier(type_w_length)) && get_modifier(type_precision) != 1111)
        set_modifier(type_flags, 2);

    if (*num < 0)
    {
		set_wordifier(type_is_negative, 1);
        *num *= -1;
    }
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
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
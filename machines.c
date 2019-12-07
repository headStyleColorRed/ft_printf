#include "printf_lib.h"

int width_counter_machine(char *string, int i)
{
	char *spaces_string;
	int j;

	spaces_string = (char *)ft_calloc(5, 1);
	j = 0;
	while (string[i] >= 48 && string[i] <= 57)
		spaces_string[j++] = string[i++];
	modifier.width = ft_atoi(spaces_string);
	free(spaces_string);
	return (j);
}

int precision_counter_machine(char *string, int i)
{
	char *dots_string;
	int j;

	dots_string = (char *)ft_calloc(5, 1);
	j = 0;
	while (string[i] >= 48 && string[i] <= 57)
		dots_string[j++] = string[i++];

	modifier.precision = ft_atoi(dots_string);
	free(dots_string);
	return (j + 1);
	
}

int manage_wildcard(long int num, int option)
{
	if (option == 1)
    {
	    modifier.width = num;
	    return (len(num));
    }
    else
    {
	    modifier.precision = num;
	    return (len(num) + 1);
    }
    
}
#include "printf_lib.h"

int width_counter_machine(char *string, int i)
{
	char *spaces_string;
	int j;
	spaces_string = (char *)ft_calloc(5, sizeof(char));
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

	dots_string = (char *)ft_calloc(5, sizeof(char));
	j = 0;
	while (string[i] >= 48 && string[i] <= 57)
		dots_string[j++] = string[i++];

	modifier.precision = ft_atoi(dots_string);
	free(dots_string);
	return (j + 1);
	
}

int manage_wildcard(long num, int option)
{
	if (option == 1)
    {
		if (num < 0)
		{
			num *= -1;
			modifier.flags = 1;
			modifier.to_modifie = 1;
		}
	    modifier.width = num;
	    return (1);
    }
    else
    {
		if (num < 0)
		{
			num *= -1;
			modifier.flags = 1;
			modifier.to_modifie = 1;
	    	modifier.width = num;
		}
		else 
	    	modifier.precision = num;
	    return (2);
    }
    
}
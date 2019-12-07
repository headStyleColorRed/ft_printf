#include "printf_lib.h"

int check_for_flags(char *string, int i)
{
    if (string[i] == '-')
    {
        modifier.flags = 1;
        modifier.to_modifie = 1;
    }
    else if(string[i] == '0')
        modifier.flags = 2;
    else
        return (0);
    return (1);
}

int check_for_width(char *string, int i, va_list arguments)
{
    int j;

    j = 0;
    if (string[i] >= '1' && string[i] <= '9')
    {
        j += width_counter_machine(string, i);
    }
    else if (string[i] == '*')
    {
        j += manage_wildcard(va_arg(arguments, int), 1);
    }
    else
        return (0);
    return (j);
}

int check_for_precision(char *string, int i, va_list arguments)
{
    int j;
    j = 0;
     if (string[i] == '.' && string[i + 1] != '*')
    {
        j += precision_counter_machine(string, i + 1);
    }
    else if(string[i] == '.' && string[i + 1] == '*')
    {
        j += manage_wildcard(va_arg(arguments, int), 2);
    }
    else
        return (0);
    return (j);
}

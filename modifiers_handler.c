#include "printf_lib.h"

// printf("(minus_counter = %d && mwordifier.length == %c", minus_counter, wordifier.length);

void no_flags()
{
    int minus_counter;
    int i;
    i = 0;
    minus_counter = modifier.width;
    while (minus_counter-- > wordifier.length)
    {
        write(1, " ", 1);
        i++;
    }
    modifier.length += i;
}

void added_flag()
{
    int minus_counter;
    int result;

    minus_counter = modifier.width;
    if (modifier.width > 0 && modifier.flags == 2)
    {
        if (wordifier.is_negative)
        {
            write(1, "-", 1);
            if (modifier.precision != 1111)
            {
        modifier.length++; //cambiado
                minus_counter++;
            }
        }
        while (minus_counter-- > wordifier.length)
            write(1, "0", 1);
        result = modifier.width - wordifier.length;
        if (result > 0)
            modifier.length += modifier.width - wordifier.length;
    }
}

void print_front_spaces()
{
    int minus_counter;

    minus_counter = modifier.width;
    while (minus_counter-- > wordifier.length)
        write(1, " ", 1);
    if (modifier.width > wordifier.length)
        modifier.length += modifier.width - wordifier.length;
}

// Option 1 -> Before printing;
// Option 2 -> After printing;
int handle_flags(int option)
{
    if (option == 1)
    {
        if (modifier.flags != 0)
            added_flag();
        else
            no_flags();
    }
    else if (option == 2 && modifier.to_modifie == 1)
    {
        print_front_spaces();
    }
    else
        return (0);

    return (0);
}

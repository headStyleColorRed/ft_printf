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

void print_spaces(int spaces_to_write)
{

    if (spaces_to_write > 0 && modifier.flags != 2)
        modifier.length += spaces_to_write;

    while (spaces_to_write-- > 0)
        write(1, " ", 1);
}

void added_flag()
{
    int spaces_to_write;
    int zeros_to_write;
    int written_result;
    int result;

    spaces_to_write = modifier.width;
    zeros_to_write = modifier.precision;
    written_result = 0;
    result = 0;
    if (modifier.flags == 2)
    {
        if (spaces_to_write > zeros_to_write)
        {
            if (zeros_to_write > wordifier.length)
            {
            if (wordifier.is_negative)
                spaces_to_write--;
                print_spaces(spaces_to_write - zeros_to_write);
                result += spaces_to_write - zeros_to_write;
            }
            else
            {
                print_spaces(spaces_to_write - wordifier.length);
                result += spaces_to_write - wordifier.length;
            }
        }
        if (modifier.precision != 1111)
        {
            zeros_to_write = modifier.precision - wordifier.length;
            //printf("zeros_to_write: %d;\n", zeros_to_write);
            if (wordifier.is_negative)
            {
                write(1, "-", 1);
                zeros_to_write++;
                wordifier.is_negative = 0;
            }
            while (zeros_to_write-- > 0)
            {
                write(1, "0", 1);
                result++;
            }
        }
        else
        {
            zeros_to_write = modifier.width - wordifier.length;
            // printf("zeros_to_write: %d;\n", zeros_to_write);
            if (wordifier.is_negative)
            {
                write(1, "-", 1);
                wordifier.is_negative = 0;
            }
            while (zeros_to_write-- > 0)
            {
                write(1, "0", 1);
                result++;
            }
        }
    }
    if (modifier.flags == 3)
    {
        zeros_to_write = modifier.precision - wordifier.length;
        if (wordifier.is_negative)
        {
            write(1, "-", 1);
            zeros_to_write++;
        }
        modifier.width -= zeros_to_write;
        while (zeros_to_write-- > 0)
        {
            write(1, "0", 1);
            wordifier.is_negative = 0;
            result++;
        }
    }
    modifier.length += result;
}

// Option 1 -> Before printing;
// Option 2 -> After printing;
int handle_flags(int option)
{
    //print_modifiers();
    if (option == 1)
    {
        if (modifier.flags != 0)
            added_flag();
        else
            no_flags();
    }
    else if (option == 2 && modifier.to_modifie == 1)
    {
        print_spaces(modifier.width - wordifier.length);
    }
    else
        return (0);

    return (0);
}

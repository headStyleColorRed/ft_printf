#include "printf_lib.h"

void no_flags()
{
    int minus_counter;
    int i;

    i = 0;
    minus_counter = get_modifier(type_width);
    while (minus_counter-- > get_wordifier(type_w_length))
    {
        write(1, " ", 1);
        i++;
    }
	add_to_length(type_length, i);
}

void print_spaces(int spaces_to_write)
{

    if (spaces_to_write > 0 && get_modifier(type_flags) != 2)
        add_to_length(type_length, spaces_to_write);

    while (spaces_to_write-- > 0)
        write(1, " ", 1);
}

void added_flag()
{
    int spaces_to_write;
    int zeros_to_write;
    int written_result;
    int result;

    spaces_to_write = get_modifier(type_width);
    zeros_to_write = get_modifier(type_precision);
    written_result = 0;
    result = 0; 
    if (get_modifier(type_flags) == 2)
    {
        if (spaces_to_write > zeros_to_write)
        {
            if (zeros_to_write > get_wordifier(type_w_length))
            {
                if (get_wordifier(type_is_negative))
                    spaces_to_write--;
                print_spaces(spaces_to_write - zeros_to_write);
                result += spaces_to_write - zeros_to_write;
            }
            else
            {
                print_spaces(spaces_to_write - get_wordifier(type_w_length));
                result += spaces_to_write - get_wordifier(type_w_length);
            }
        }
        if (get_modifier(type_precision) != 1111)
        {
            zeros_to_write = get_modifier(type_precision) - get_wordifier(type_w_length);
            if (get_wordifier(type_is_negative))
            {
                write(1, "-", 1);
                zeros_to_write++;
                set_wordifier(type_is_negative, 0);
            }
            while (zeros_to_write-- > 0)
            {
                write(1, "0", 1);
                result++;
            }
        }
        else
        {
            zeros_to_write = get_modifier(type_width) - get_wordifier(type_w_length);
            if (get_wordifier(type_is_negative))
            {
                write(1, "-", 1);
				set_wordifier(type_is_negative, 0);
            }
            while (zeros_to_write-- > 0)
            {
                write(1, "0", 1);
                result++;
            }
        }
    }
    if (get_modifier(type_flags) == 3)
    {
        zeros_to_write = get_modifier(type_precision) - get_wordifier(type_w_length);
        if (get_wordifier(type_is_negative))
        {
            write(1, "-", 1);
            zeros_to_write++;
        }
		substract_to_length(type_width, zeros_to_write);
        while (zeros_to_write-- > 0)
        {
            write(1, "0", 1);
            set_wordifier(type_is_negative, 0);
            result++;
        }
    }
	add_to_length(type_length, result);
}

// Option 1 -> Before printing;
// Option 2 -> After printing;
int handle_flags(int option)
{
    if (option == 1)
    {
        if (get_modifier(type_flags) != 0)
            added_flag();
        else
            no_flags();
    }
    else if (option == 2 && get_modifier(type_to_modifie) == 1)
    {
        print_spaces(get_modifier(type_width) - get_wordifier(type_w_length));
    }
    else
        return (0);

    return (0);
}

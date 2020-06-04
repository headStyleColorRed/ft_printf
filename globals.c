//
//  globals.c
//  ft_printf
//
//  Created by Rodrigo  on 01/05/2020.
//  Copyright © 2020 Rodrigo . All rights reserved.
//

#include "printf_lib.h"

static int flags;
static int width;
static int precision;
static char specifier;
static int length;
static int to_modifie;
static int w_length;
static int is_negative;
static int is_ptr;
static int is_hex;
static int is_num;

void getModifiers(void)
{
    printf("flags: %d\n", flags);
    printf("width: %d\n", width);
    printf("precision: %d\n", precision);
    printf("specifier: %c\n", specifier);
    printf("length: %d\n", length);
    printf("to_modifie: %d\n", to_modifie);
    printf("w_length: %d\n", w_length);
    printf("is_negative: %d\n", is_negative);
    printf("is_ptr: %d\n", is_ptr);
    printf("is_hex: %d\n", is_hex);
    printf("is_num: %d\n", is_num);
}

void initialize_globals(void)
{
    flags = 0;
    width = 0;
    precision = 1111;
    to_modifie = 0;
    specifier = '0';
    w_length = 0;
    is_negative = 0;
    is_ptr = 0;
    is_hex = 0;
    is_num = 0;
}


void set_modifier(char *str, int amount, char spec)
{
    
    if (!ft_strncmp(str, "flags", 5))
        flags = amount;
    else if (!ft_strncmp(str, "width", 5))
        width = amount;
    else if (!ft_strncmp(str, "precision", 5))
        precision = amount;
    else if (!ft_strncmp(str, "specifier", 5))
        specifier = spec;
    else if (!ft_strncmp(str, "length", 5))
        length = amount;
    else if (!ft_strncmp(str, "to_modifie", 5))
        to_modifie = amount;
}

void set_wordifier(char *str, int amount)
{
    
    if (!ft_strncmp(str, "w_length", 5))
        w_length = amount;
    else if (!ft_strncmp(str, "is_negative", 5))
        is_negative = amount;
    else if (!ft_strncmp(str, "is_ptr", 5))
        is_ptr = amount;
    else if (!ft_strncmp(str, "is_hex", 5))
        is_hex = amount;
    else if (!ft_strncmp(str, "is_num", 5))
        is_num = amount;
}

int get_modifier(char *str)
{
    
    if (!ft_strncmp(str, "flags", 5))
        return flags;
    else if (!ft_strncmp(str, "width", 5))
        return width;
    else if (!ft_strncmp(str, "precision", 5))
        return precision;
    else if (!ft_strncmp(str, "specifier", 5))
        return specifier;
    else if (!ft_strncmp(str, "length", 5))
        return length;
    else if (!ft_strncmp(str, "to_modifie", 5))
        return to_modifie;
    else
        return 0;
}

int get_wordifier(char *str)
{
    
    if (!ft_strncmp(str, "w_length", 5))
        return w_length;
    else if (!ft_strncmp(str, "is_negative", 5))
        return is_negative;
    else if (!ft_strncmp(str, "is_ptr", 5))
        return is_ptr;
    else if (!ft_strncmp(str, "is_hex", 5))
        return is_hex;
    else if (!ft_strncmp(str, "is_num", 5))
        return is_num;
    else
        return 0;
}

void add_to_length(char *str, int amount)
{
    if (!ft_strncmp(str, "length", 5))
        length += amount;
    else if (!ft_strncmp(str, "w_length", 5))
        w_length += amount;
    else if (!ft_strncmp(str, "width", 5))
        width += amount;
}

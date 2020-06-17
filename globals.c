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
static int specifier;
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
    printf("specifier: %d\n", specifier);
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
    specifier = 0;
    w_length = 0;
    is_negative = 0;
    is_ptr = 0;
    is_hex = 0;
    is_num = 0;
}


void set_modifier(int e_printType, int amount)
{
    
    if (e_printType == type_flags)
        flags = amount;
    else if (e_printType == type_width)
        width = amount;
    else if (e_printType == type_precision)
        precision = amount;
    else if (e_printType == type_specifier)
        specifier = amount;
    else if (e_printType == type_length)
        length = amount;
    else if (e_printType == type_to_modifie)
        to_modifie = amount;
}

void set_wordifier(int e_printType, int amount)
{
    
    if (e_printType == type_w_length)
        w_length = amount;
    else if (e_printType == type_is_negative)
        is_negative = amount;
    else if (e_printType == type_is_ptr)
        is_ptr = amount;
    else if (e_printType == type_is_hex)
        is_hex = amount;
    else if (e_printType == type_is_num)
        is_num = amount;
}

int get_modifier(int e_printType)
{
    
    if (e_printType == type_flags)
        return flags;
    else if (e_printType == type_width)
        return width;
    else if (e_printType == type_precision)
        return precision;
    else if (e_printType == type_specifier)
        return specifier;
    else if (e_printType == type_length)
        return length;
    else if (e_printType == type_to_modifie)
        return to_modifie;
    else
        return 0;
}

int get_wordifier(int e_printType)
{
    
    if (e_printType == type_w_length)
        return w_length;
    else if (e_printType == type_is_negative)
        return is_negative;
    else if (e_printType == type_is_ptr)
        return is_ptr;
    else if (e_printType == type_is_hex)
        return is_hex;
    else if (e_printType == type_is_num)
        return is_num;
    else
        return 0;
}

void add_to_length(int e_printType, int amount)
{
    if (e_printType == type_length)
        length += amount;
    else if (e_printType == type_w_length)
        w_length += amount;
    else if (e_printType == type_width)
        width += amount;
}

void substract_to_length(int e_printType, int amount)
{
    if (e_printType == type_width)
        width -= amount;
    else if (e_printType == type_length)
        length -= amount;
}

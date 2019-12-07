
#ifndef PRINTF_LIB_H
#define PRINTF_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

/*
    M O D E L  ---> %[flags][width][.precision][length]specifier

    Flags:
        - 1 (-)                 - 2 (0)

    Width:
        -  * -> (integer)       - integer

    Precision:
        - integer               - * -> (integer)

    Specifier:
        - %c    - %s    - %p    - %d    - %i
        - %u    - %x    - %X     - %%
    To Modifie:
        - 1 (yes)               - 0 (no)
*/

typedef struct Node
{
    int flags;
    int width;
    int precision;
    char specifier;
    int length;
    int to_modifie;

} Modifiers;


typedef struct node
{
    int length;
    int is_negative;

} Wordifiers;

Modifiers modifier;
Wordifiers wordifier;

// Main Functions
int ft_printf(const char *, ...);
int flag_managment(char *string, int i, va_list arguments);
int string_parser(char *string, int i, va_list arguments);

// Checkers
int check_for_flags(char *string, int i);
int check_for_width(char *string, int i, va_list arguments);
int check_for_precision(char *string, int i, va_list arguments);

// Machines
int width_counter_machine(char *string, int i);
int precision_counter_machine(char *string, int i);
int manage_wildcard(long int num, int option);

// Printers
void print_c(int character);
void print_s(char *string);
void print_d(int num);
int print_u(unsigned int num);

// Extras
void initialize_struct();
void	*ft_calloc(size_t nitems, size_t size);
int		ft_strlen(char *str);
int		ft_strcpy(char *dest, char *src);
void print_modifiers();             //  B O R R A R

// Modifiers Handlers
int handle_flags(int option);

// Alone files
char		*ft_itoa(int number);
int	len(long number);


int	ft_atoi(const char *str);

#endif
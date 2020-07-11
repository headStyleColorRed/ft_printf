/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_lib.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 23:39:37 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/11 19:17:59 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_LIB_H
# define PRINTF_LIB_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*
**    M O D E L  ---> %[flags][width][.precision][length]specifier
**
**    Flags:
**        - 1 (-)                 - 2 (0)
**
**    Width:
**        -  * -> (integer)       - integer
**
**    Precision:
**        - integer               - * -> (integer)
**
**    Specifier:
**        - %c    - %s    - %p    - %d    - %i
**        - %u    - %x    - %X     - %%
**    To Modifie:
**        - 1 (yes)               - 0 (no)
*/

typedef enum		e_print_type
{
	type_flags,
	type_width,
	type_precision,
	type_specifier,
	type_length,
	type_to_modifie,
	type_w_length,
	type_is_negative,
	type_is_ptr,
	type_is_hex,
	type_is_num,
}					t_type;

typedef struct		s_globals
{
	int flags;
	int width;
	int precision;
	int specifier;
	int length;
	int to_modifie;
	int w_length;
	int is_negative;
	int is_ptr;
	int is_hex;
	int is_num;
}					t_globals;

t_globals			g_global_variables;

/*
**	*	*	Main Functions	*	*	**
*/

int					ft_printf(const char *format, ...);
int					flag_managment(char *string, int i, va_list arguments);
int					string_parser(char *string, int i, va_list arguments);

/*
**	*	*	Checkers	*	*	**
*/

int					check_for_flags(char *string, int i);
int					check_for_width(char *string, int i, va_list arguments);
int					check_for_precision(char *string, int i, va_list arguments);

/*
**	*	*	Machines	*	*	**
*/

int					width_counter_machine(char *string, int i);
int					precision_counter_machine(char *string, int i);
int					manage_wildcard(long int num, int option);

/*
**	*	*	Printers	*	*	**
*/

void				print_c(int character);
void				print_s(char *string);
void				print_d(int num);
void				print_u(unsigned int num);
int					print_x(int num);
int					print_big_x(int num);
void				print_p(unsigned long int num);
void				print_percent(void);
void				print_unknown(char unknown);
int					print_unmodified_s(char *string);

/*
**	*	*	Extras	*	*	**
*/

void				*ft_calloc(size_t nitems, size_t size);
int					ft_strlen(char *str);
int					ft_strcpy(char *dest, char *src);
void				print_nulls(char *string);
int					ft_isalnum(int c);
int					only_zero_exception(int num);
void				pre_handle_flags_integer(int *num);
void				pre_handle_flags_hexadecimal(char *str);
void				pre_handle_flags_unsigned(unsigned int *num);
int					ft_strncmp(char *s1, char *s2, unsigned int n);

/*
**	*	*	Modifiers Handlers	*	*	**
*/

int					handle_flags(int option);
void				print_spaces(int spaces_to_write);

/*
**	*	*	Flag Handlers	*	*	**
*/

int					handler_zero_flag();
int					flag_one_handler();
int					flag_two_handler();

/*
**	*	*	Alone files	*	*	**
*/

char				*ft_itoa(int number);
char				*ft_u_itoa(unsigned int number);
int					ft_putnbr_base(unsigned long long int nbr, char *base);
int					len(long number);
int					ft_atoi(const char *str);

/*
**	*	*	Globals	*	*	**
*/

void				initialize_globals(void);
void				add_to_length(int e_print_type, int amount);
int					get_wordifier(int e_print_type);
int					get_modifier(int e_print_type);
void				set_wordifier(int e_print_type, int amount);
void				set_modifier(int e_print_type, int amount);
void				substract_to_length(int e_print_type, int amount);

#endif

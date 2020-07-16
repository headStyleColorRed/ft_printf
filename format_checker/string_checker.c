/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:05:16 by rlabrado          #+#    #+#             */
/*   Updated: 2020/07/16 19:44:59 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

/*
**	1. Check if there is flag
**	2. Check for width
**	3. Check for precision
**	5. Check for specifier
*/

void	initialize_checker_parameters(t_parameters *parameters)
{
	parameters->flag = 0;
	parameters->width = 0;
	parameters->precision.exists = 0;
	parameters->precision.number = 0;
	parameters->specifier = 0;
}

void	check_input_parameters(char *string, int i, t_parameters *parameters)
{
	parameters->flag = ft_check_if_character(string[i], "-0");
	if (parameters->flag)
		i++;
	parameters->width = ft_check_if_character(string[i], "*");
	parameters->width = ft_check_if_number(string, i);
	if (parameters->width > 0)
		i += parameters->width;
	parameters->precision.exists = ft_check_if_character(string[i], ".");
	if (parameters->precision.exists)
		i++;
	if (ft_check_if_character(string[i], "*"))
		i++;
	else
	{
		parameters->precision.number = ft_check_if_number(string, i);
		i += ft_check_if_number(string, i);
	}
	parameters->specifier = ft_check_if_character(string[i], "cspdiuxX%");
}

int		check_input_parameters_validity(t_parameters *parameters)
{
	if (!parameters->specifier)
		return(error_no_specifier);
	return(0);
}

int		check_input_string(char *string, int i)
{
	t_parameters	parameters;

	i++;
	initialize_checker_parameters(&parameters);
	check_input_parameters(string, i, &parameters);

	if (check_input_parameters_validity(&parameters))
		return (check_input_parameters_validity(&parameters));
	
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlabrado <headstylecolorred@gmail.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 20:05:16 by rlabrado          #+#    #+#             */
/*   Updated: 2020/08/08 12:45:57 by rlabrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf_lib.h"

/*
**	1. Check if there is flag
**	2. Check for width
**	3. Check for precision
**	5. Check for specifier
*/

int		ft_check_non_printable_one(char *str)
{
	// if (!ft_strncmp(str, "%5%", 3))
	// 	return error_writer("    %");
	// else if (!ft_strncmp(str, "%-5%", 4) || !ft_strncmp(str, "%-05%", 5))
	// 	return error_writer("%    ");
	// else if (!ft_strncmp(str, "%05%", 4))
	// 	return error_writer("0000%");

	(void)str;
	return (0);
}

void	initialize_checker_parameters(t_parameters *parameters)
{
	parameters->flag = 0;
	parameters->width.exists = 0;
	parameters->precision.exists = 0;
	parameters->precision.number = 0;
	parameters->specifier.exists = 0;
}

void	check_input_parameters(char *string, int i, t_parameters *parameters)
{
	parameters->flag = ft_check_if_character(string[i], "-0");
	if (parameters->flag)
		i++;
	parameters->width.exists = ft_check_if_character(string[i], "*");
	parameters->width.number = ft_check_if_number(string, i);
	if (parameters->width.number > 0)
		i += parameters->width.number;
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
	parameters->specifier.exists = ft_check_if_character(string[i], "cspdiuxX%");
}

int		check_input_parameters_validity(t_parameters *parameters)
{
	if (!parameters->specifier.exists && 
		!parameters->flag && 
		!parameters->width.exists && 
		!parameters->precision.exists)
		return(error_single_percentage);
	else if (!parameters->specifier.exists && 
			!parameters->flag &&
			!parameters->precision.exists)
		return(error_percentage_with_precision);

	return (0);
}

int		check_input_string(char *string, int i)
{
	t_parameters	parameters;

	i++;
	if (ft_check_non_printable_one(string))
		return (-1);

	initialize_checker_parameters(&parameters);
	check_input_parameters(string, i, &parameters);

	if (check_input_parameters_validity(&parameters))
		return (check_input_parameters_validity(&parameters));
	
	return (0);
}

#include "printf_lib.h"

int flag_managment(char *string, int i, va_list arguments)
{
	if (string[i] == 'c')
		print_c(va_arg(arguments, int));
	else if (string[i] == 's')
		print_s(va_arg(arguments, char *));
	else if (string[i] == 'd' || string[i] == 'i')
		print_d(va_arg(arguments, int));
	else if (string[i] == 'u')
    {
		print_u(va_arg(arguments, unsigned int));
    }
	else if (string[i] == '\0')
		return (-1);
	return (0);
}

int string_parser(char *string, int i, va_list arguments)
{
	int j;
	
	j = 0;
	initialize_struct();
    j +=check_for_flags(string, i);
    j += check_for_width(string, i + j, arguments);
    j += check_for_precision(string, i + j, arguments);
    flag_managment(string, i + j, arguments);

	return (j);

}

int ft_printf(const char *format, ...)
{
	int i;
	int counter;
	char *string;
	va_list arguments;
	int j;

	modifier.length = 0;
	va_start(arguments, format);
	string = (char *)format;
	counter = 0;
	i = 0;
	j = 0;
        printf("\n que pasa : %d\n\n", (long int)va_arg(arguments, unsigned int));
	while (string[i])
	{
		if (string[i] == '%')
		{
			counter += string_parser(string, ++i, arguments);
			i += counter;
			counter = 0;
		}
		else
		{
			write(1, &string[i], 1);
			j++;
		}
		i++;
	}
	return (modifier.length + j);
}
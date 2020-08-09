
#include "../printf_lib.h"

int		undefined_behaviour_p()
{
	int precision;
	int width;

	precision = get_modifier(type_precision);
	width = get_modifier(type_width);
	if (width && precision != 999999 && precision > width)
	{
		initialize_globals();
		print_s("0x0000004d2");
		return (1);
	} else if (!width && precision != 999999 && precision )
	{
		initialize_globals();
		print_s("0x00000");
		return (1);
	}
	return (0);
}
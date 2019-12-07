#include "printf_lib.h"

int pointeando()
{
	int my_total;
	int his_total;
	int *b = &my_total;
	int *c = &his_total;

	printf("\n\n\n\n\n\n+++++++++++ Probamos con POINTERS!:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %p\n", "me pasan aquí.", b);
	his_total = printf("Vaya qué cosas %s con numeros como el %p\n", "me pasan aquí.", b);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con POINTERS!:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %20p\n", "me pasan aquí.", c);
	his_total = printf("Vaya qué cosas %s con numeros como el %20p\n", "me pasan aquí.", c);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con POINTERS!:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %20p\n", "me pasan aquí.", b);
	his_total = printf("Vaya qué cosas %s con numeros como el %20p\n", "me pasan aquí.", b);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con POINTERS!:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %*p\n", "me pasan aquí.", 20, c);
	his_total = printf("Vaya qué cosas %s con numeros como el %*p\n", "me pasan aquí.", 20, c);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}



	return (0);
}

int hexadecimal()
{
	int my_total;
	int his_total;

	printf("\n\n\n\n\n\n+++++++++++ Probamos con HEXADCIMAL:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %x\n", "me pasan aquí.", 15);
	his_total = printf("Vaya qué cosas %s con numeros como el %x\n", "me pasan aquí.", 15);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con HEXADCIMAL:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %10x\n", "me pasan aquí.", 15);
	his_total = printf("Vaya qué cosas %s con numeros como el %10x\n", "me pasan aquí.", 15);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con HEXADCIMAL:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %.3x\n", "me pasan aquí.", 15529);
	his_total = printf("Vaya qué cosas %s con numeros como el %.3x\n", "me pasan aquí.", 15529);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con HEXADCIMAL:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %*.*x\n", "me pasan aquí.", 15, 3, 15529);
	his_total = printf("Vaya qué cosas %s con numeros como el %*.*x\n", "me pasan aquí.", 15, 3, 15529);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con HEXADCIMAL:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %010x\n", "me pasan aquí.", 2147483647);
	his_total = printf("Vaya qué cosas %s con numeros como el %010x\n", "me pasan aquí.", 2147483647);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con HEXADCIMAL:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %10x\n", "me pasan aquí.", -2147483647);
	his_total = printf("Vaya qué cosas %s con numeros como el %10x\n", "me pasan aquí.", -2147483647);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	return (0);
}

int unsigned_testing()
{
	int my_total;
	int his_total;

	printf("\n\n\n\n\n\n+++++++++++ Probamos con UNSIGNED:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %u\n", "me pasan aquí.", 15);
	his_total = printf("Vaya qué cosas %s con numeros como el %u\n", "me pasan aquí.", 15);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con UNSIGNED:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %10u\n", "me pasan aquí.", 15);
	his_total = printf("Vaya qué cosas %s con numeros como el %10u\n", "me pasan aquí.", 15);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con UNSIGNED:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %.3u\n", "me pasan aquí.", 15529);
	his_total = printf("Vaya qué cosas %s con numeros como el %.3u\n", "me pasan aquí.", 15529);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con UNSIGNED:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %*.*u\n", "me pasan aquí.", 15, 3, 15529);
	his_total = printf("Vaya qué cosas %s con numeros como el %*.*u\n", "me pasan aquí.", 15, 3, 15529);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con UNSIGNED:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %010u\n", "me pasan aquí.", 2147483647);
	his_total = printf("Vaya qué cosas %s con numeros como el %010u\n", "me pasan aquí.", 2147483647);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	return (0);
}

int integer_testing()
{
	int my_total;
	int his_total;

	printf("\n\n\n\n\n\n+++++++++++ Probamos con INTEGERSs:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %d\n", "me pasan aquí.", 15);
	his_total = printf("Vaya qué cosas %s con numeros como el %d\n", "me pasan aquí.", 15);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con INTEGERS:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %10d\n", "me pasan aquí.", 15);
	his_total = printf("Vaya qué cosas %s con numeros como el %10d\n", "me pasan aquí.", 15);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con INTEGERSs:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %.3d\n", "me pasan aquí.", 15529);
	his_total = printf("Vaya qué cosas %s con numeros como el %.3d\n", "me pasan aquí.", 15529);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con INTEGERSs:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %*.*d\n", "me pasan aquí.", 15, 3, 15529);
	his_total = printf("Vaya qué cosas %s con numeros como el %*.*d\n", "me pasan aquí.", 15, 3, 15529);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con INTEGERS:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %010d\n", "me pasan aquí.", 2147483647);
	his_total = printf("Vaya qué cosas %s con numeros como el %010d\n", "me pasan aquí.", 2147483647);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con INTEGERS:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s con numeros como el %010d\n", "me pasan aquí.", -23647);
	his_total = printf("Vaya qué cosas %s con numeros como el %010d\n", "me pasan aquí.", -23647);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	return (0);
}

int string_tester()
{
	int my_total;
	int his_total;

	printf("\n\n\n\n\n\n+++++++++++ Probamos con %%s:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %s\n", "me pasan aquí.");
	his_total = printf("Vaya qué cosas %s\n", "me pasan aquí.");
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con %%s:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %20s\n", "me pasan aquí.");
	his_total = printf("Vaya qué cosas %20s\n", "me pasan aquí.");
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con %%s:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %-20s\n", "me pasan aquí.");
	his_total = printf("Vaya qué cosas %-20s\n", "me pasan aquí.");
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con %%s:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %20.5s\n", "me pasan aquí.");
	his_total = printf("Vaya qué cosas %20.5s\n", "me pasan aquí.");
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con %%s:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %*.*s\n", 17, 6, "me pasan aquí.");
	his_total = printf("Vaya qué cosas %*.*s\n", 17, 6, "me pasan aquí.");
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n\n\n\n\n+++++++++++ Probamos con %%s:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cosas %*.*s\n", 5, 15, "me pasan aquí.");
	his_total = printf("Vaya qué cosas %*.*s\n", 5, 15, "me pasan aquí.");
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	return (0);
}

int char_tester(void)
{

	int my_total;
	int his_total;

	printf("\n+++++++++ M Y   L A Z Y   T E S T E R ++++++++++++\n");

	printf("\n\n +++++++++++++++ Probamos con %%c:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cos%cs\n", 'a');
	his_total = printf("Vaya qué cos%cs\n", 'a');
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n +++++++++++++++ Probamos con %%c:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cos%10cs\n", 'a');
	his_total = printf("Vaya qué cos%10cs\n", 'a');
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n +++++++++++++++ Probamos con %%c:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cos%-10cs\n", 'a');
	his_total = printf("Vaya qué cos%-10cs\n", 'a');
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	printf("\n\n +++++++++++++++ Probamos con %%c:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cos%*cs\n", 10, 'a');
	his_total = printf("Vaya qué cos%*cs\n", 10, 'a');
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
	{
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");
		return (1);
	}

	return (0);
}

int call_functions()
{
	int result;
	result = char_tester();
	if (result == 1)
		return (0);

	result = string_tester();
	if (result == 1)
		return (0);

	result = integer_testing();
	if (result == 1)
		return (0);

	result = unsigned_testing();
	if (result == 1)
		return (0);

	result = hexadecimal();
	if (result == 1)
		return (0);

	result = pointeando();
	if (result == 1)
		return (0);

	printf("\n                             \n");
	printf("        # # #   #    #         \n");
	printf("        #   #   #  #           \n");
	printf("        #   #   #              \n");
	printf("        #   #   # #            \n");
	printf("        # # #   #   #          \n");
	printf("\n                             \n");

	return (0);
}

int main(void)
{
	//int *b = &his_total;
	int result;

	result = call_functions();
	if (result == 0)
		return (0);

	return (0);
}

/*

	int main(void)
	{
		int my_total;
		int his_total;

		my_total = ft_printf("Vaya |%17.15x|\n", -214647);
		his_total = printf("Vaya |%17.15x|\n", -214647);
		printf("My total -> %d\n", my_total);
		printf("Histotal -> %d\n", his_total);
}
*/
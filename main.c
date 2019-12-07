#include "printf_lib.h"


int main(void)
{
	int my_total;
	int his_total;
	int *b = &his_total;

	printf("\n+++++++++ M Y   L A Z Y   T E S T E R ++++++++++++\n");
	printf("\n\n +++++++++++++++ Probamos con %%c:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya qué cos%cs\n", 'a');
	his_total = printf("Vaya qué cos%cs\n", 'a');
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");

	printf("\n\n +++++++++++++++ Probamos con %%s:  ++++++++++++++++++\n");
	my_total = ft_printf("Parece que todo %s\n", "funciona bien!");
	his_total = printf("Parece que todo %s\n", "funciona bien!");
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");

	printf("\n\n +++++++++++++++ Probamos con %%u:  ++++++++++++++++++\n");
	my_total = ft_printf("%u as\n", 234867);
	his_total = printf("%u as\n", 234867);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");

	printf("\n\n +++++++++++++++ Probamos con %%d:  ++++++++++++++++++\n");
	my_total = ft_printf("el numero es: %d\n", 23);
	his_total = printf("el numero es: %d\n", 23);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");

	printf("\n\n +++++++++++++++ Probamos con %%x:  ++++++++++++++++++\n");
	my_total = ft_printf("hexadecima uwu! %x\n", 2342867);
	his_total = printf("hexadecima uwu! %x\n", 2342867);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");

	printf("\n\n +++++++++++++++ Probamos con %%X:  ++++++++++++++++++\n");
	my_total = ft_printf("hexadecima uwu! %X\n", 2342867);
	his_total = printf("hexadecima uwu! %X\n", 2342867);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");

	printf("\n\n +++++++++++++++ Probamos con %%i:  ++++++++++++++++++\n");
	my_total = ft_printf("y los itegers como %i\n", 2867);
	his_total = printf("y los itegers como %i\n", 2867);
	printf("My total -> %d\n", my_total);
	printf("Histotal -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");


	printf("\n\n +++++++++++++++ Probamos con espacios:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya %20d cosas que %% %s\n", 10, "me están pasando.");
	his_total = printf("Vaya %20d cosas que %% %s\n", 10, "me están pasando.");
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");


	printf("\n\n +++++++++++++++ Probamos con ceros:  ++++++++++++++++++\n");
	my_total = ft_printf("Vaya %04d cosas que %% %s\n", -10, "me están pasando.");
	his_total = printf("Vaya %04d cosas que %% %s\n", -10, "me están pasando.");
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");


	printf("\n\n +++++++++++++++ Probamos mezcla de ceros y espacios:  ++++++++++++++++++\n");
	my_total = ft_printf("%-15d %s aquí tenemos un %% además de %c%c hexadecimal %08d\n", -10, "hola que pasa", 'u', 'n', 2342);
	his_total = printf("%-15d %s aquí tenemos un %% además de %c%c hexadecimal %08d\n", -10, "hola que pasa", 'u', 'n', 2342);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");


	printf("\n\n +++++++++++++++ Probamos los punteros!:  ++++++++++++++++++\n");
	my_total = ft_printf("frase |%-20p|\n", b);
	his_total = printf("frase |%-20p|\n", b);
	printf("My  total -> %d\n", my_total);
	printf("His total -> %d\n", his_total);
	if (my_total != his_total)
		printf("MAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAL!!!!!!!!!!!!\n");

	return (0);
}


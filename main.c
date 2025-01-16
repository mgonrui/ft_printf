#include "ft_printf.h"

// DONE %c imprime un caracter
// DONE %s Imprime una string (como se define por defecto en C).
// TODO %p el puntero void * dado como argumento se imprime en formato hexadecimal.
// TODO %d imprime un número decimal (base 10).
// TODO %i imprime un entero en base 10.
// TODO %u imprime un número decimal (base 10) sin signo.
// TODO %x imprime un número hexadecimal (base 16) en minúsculas.
// TODO %x imprime un número hexadecimal (base 16) en mayúsculas.
// DONE %% para imprimir el símbolo del porcentaje.


int main (int argc, char **argv)
{
	if (argc <= 1)
	{
		printf("You did not write any args\n");
		return (0);
	}
	int ret_value;
	ret_value = ft_printf("%d", atoi(argv[1]));
	printf("\nret value: %d\n", ret_value);

	printf("\nprintf:\n");
	ret_value = printf("%d", atoi(argv[1]));
	printf("\nret value: %d\n", ret_value);

	return (0);
}

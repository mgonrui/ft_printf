#include "ft_printf.h"


int main (void)
{
	/* if (argc <= 1) */
	/* { */
	/* 	printf("You did not write any args\n"); */
	/* 	return (0); */
	/* } */
	int ret_value;
	/* int number = 42; */
	/* int *p_number = &number; */

	ret_value = ft_printf("%s", NULL);
	printf("\nret value: %d\n", ret_value);

	printf("\nprintf:\n");
	ret_value = printf("%s", (char *)NULL);
	printf("\nret value: %d\n", ret_value);

	return (0);
}

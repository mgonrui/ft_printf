#include "ft_printf.h"


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

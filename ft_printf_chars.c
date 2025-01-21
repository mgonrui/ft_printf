#include "ft_printf.h"

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int ft_putstr(char *s)
{
	int i;

	if (s == NULL)
		s = "(null)";
	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	return i;
}

#include "ft_printf.h"

// DONE %c imprime un caracter
// DONE %s Imprime una string (como se define por defecto en C).
// TODO %p el puntero void * dado como argumento se imprime en formato hexadecimal.
// DONE %d imprime un número decimal (base 10).
// DONE %i imprime un entero en base 10.
// TODO %u imprime un número decimal (base 10) sin signo.
// TODO %x imprime un número hexadecimal (base 16) en minúsculas.
// TODO %x imprime un número hexadecimal (base 16) en mayúsculas.
// DONE %% para imprimir el símbolo del porcentaje.

int check_format(const char *format, va_list args)
{
    int ret_value;

    if (*format == '%')
        ret_value = ft_putchar('%');
    if (*format == 'c')
        ret_value = ft_putchar(va_arg(args, int));
    else if (*format == 's')
        ret_value = ft_putstr(va_arg(args, char *));
    else if (*format == 'd' || *format == 'i')
        ret_value = ft_print_dec(va_arg(args, int), "0123456789");
    else if (*format == 'u')
        ret_value = ft_print_dec(va_arg(args, unsigned int), "0123456789");
    else if (*format == 'x')
        ret_value = ft_print_hex(va_arg(args, unsigned int), "0123456789abcdef");
    else if (*format == 'X')
        ret_value = ft_print_hex(va_arg(args, unsigned int), "0123456789ABCDEF");
    else if (*format == 'p')
        ret_value = 0;//ft_putnbr_any_base(va_arg(args, int), "0123456789ABCDEF");
    return ret_value;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int ret_value;
    va_start(args, format);

    i = 0;
    ret_value = 0;
    while(format[i] != '\0')
    {
        if (format[i] == '%')
        {
            ret_value += (check_format(&format[i + 1], args));
            i++;
        }
        else
            ret_value += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return ret_value;
}


#include "ft_printf.h"

int check_format(const char character, va_list args)
{
    int ret_value;

    ret_value = 0;
            if (character == '%')
                ret_value += ft_putchar('%');
            if (character == 'c')
                ret_value += ft_putchar(va_arg(args, int));
            else if (character == 's')
                ret_value += ft_putstr(va_arg(args, char *));
            else if (character == 'd')
                ret_value += ft_putnbr_any_base(va_arg(args, int), "0123456789");
            else if (character == 'x')
                ret_value += ft_putnbr_any_base(va_arg(args, int), "0123456789abcdef");
            else if (character == 'X')
                ret_value += ft_putnbr_any_base(va_arg(args, int), "0123456789ABCDEF");
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
            ret_value += (check_format(format[i + 1], args));
            i++;
        }
        else
            ret_value += ft_putchar(format[i]);
        i++;
    }
    va_end(args);
    return ret_value;
}


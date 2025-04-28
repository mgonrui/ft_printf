/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:20:36 by mariogo2          #+#    #+#             */
/*   Updated: 2025/01/30 15:22:20 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *format, va_list args)
{
	int	ret_value;

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
		ret_value = ft_print_hex(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (*format == 'X')
		ret_value = ft_print_hex(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (*format == 'p')
		ret_value = ft_print_poi(va_arg(args, unsigned long long int),
				"0123456789abcdef");
	return (ret_value);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ret_value;

	va_start(args, format);
	i = 0;
	ret_value = 0;
	while (format[i] != '\0')
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
	return (ret_value);
}

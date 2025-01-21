/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_any_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgr <mgr@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 19:07:44 by mariogo2          #+#    #+#             */
/*   Updated: 2025/01/16 17:36:08 by mgr              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_calc_ret_value(unsigned long long n, int len_base)
{
	int n_chars;
	n_chars = 0;

	while(n > ((unsigned long long)len_base - 1))
	{
		n = n / len_base;
		n_chars++;
	}
	n_chars++;
	return n_chars;
}

int ft_print_dec(long long n, char *base)
{
	int sign;
	sign = 0;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		sign = 1;
	}
	if (n > 9)
	{
		ft_print_dec(n / 10, base);
		ft_print_dec(n % 10, base);
	}
	else
		ft_putchar(base[n]);
	return ft_calc_ret_value(n, 10) + sign;

}

int ft_print_hex(unsigned long long n, char *base)
{
	if (n > 15)
	{
		ft_print_hex(n / 16 , base);
		ft_print_hex(n % 16 , base);
	}
	else
		ft_putchar(base[n]);
	return ft_calc_ret_value(n, 16);

}

int ft_print_poi(unsigned long long n, char *base)
{
	if (n == 0)
		return ft_putstr("(nil)");
	ft_putstr("0x");
	return (ft_print_hex(n, base) + 2);
}

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

void write_numbers(int n, char *base)
{
	int len_base = 0;
	while (base[len_base + 1] != '\0')
		len_base++;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		ft_putnbr_any_base(n, base);
		return ;
	}
	else if (n > len_base)
	{
		ft_putnbr_any_base(n / (len_base + 1), base);
		ft_putnbr_any_base(n % (len_base + 1), base);
	}
	else
		ft_putchar(base[n]);
	return ;
}

int ft_putnbr_any_base(int n, char *base)
{
	int n_chars;
	int ncopy;
	ncopy = n;

	n_chars = 0;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return 11;
	}

	if (ncopy < 0)
	{
		ncopy = -ncopy;
		n_chars++;
	}
	while(ncopy > 9)
	{
		ncopy = ncopy / 10;
		n_chars++;
	}
	n_chars++;
	write_numbers(n, base);
	return n_chars;
}

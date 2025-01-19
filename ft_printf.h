#ifndef FT_PIRINTF_H_
#define FT_PIRINTF_H_

// headers needed for the assignment
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

// headers for testing purposes
// TODO delete when finished testing
#include <unistd.h>


int ft_printf(char const *, ...);

// helper functions
int ft_putchar(char c);
int ft_redirect_hex_neg(unsigned long long n, char *base);
int ft_print_hex(unsigned long long n, char *base);
int ft_print_dec(long long n, char *base);
int ft_putstr(char *s);

# endif // FT_PRINTF_H_

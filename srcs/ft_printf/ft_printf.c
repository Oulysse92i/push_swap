/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:26:18 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/19 15:37:21 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	print_ptr(unsigned long n);
int	print_hex(unsigned int n, char format);
int	ft_putunbr(unsigned int n);

int	check_input(const char *format, int count, va_list args)
{
	while (*format)
	{
		if (*format == '%' && (*format + 1))
		{
			format++;
			if (*format == 'c')
				count += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (*format == 'p')
				count += print_ptr(va_arg(args, unsigned long));
			else if (*format == 'd' || *format == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				count += ft_putunbr(va_arg(args, unsigned int));
			else if (*format == 'x' || *format == 'X')
				count += print_hex(va_arg(args, unsigned int), *format);
			else if (*format == '%')
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		print_out;

	if (!format)
		return (0);
	print_out = 0;
	va_start(args, format);
	print_out += check_input(format, 0, args);
	va_end(args);
	return (print_out);
}
/*
#include <stdio.h>
#include <limits.h>

int main(void)
{
	ft_printf("ft_printf 'c' : %c\n", 'a');
	printf("printf 'c' :    %c\n\n", 'a');
	ft_printf("ft_printf 's' : %s\n", "Hello world !");
	printf("printf 's' :    %s\n\n", "Hello world !");
	ft_printf("ft_printf 'p' : %p\n", (void *)0);
	printf("printf 'p' :    %p\n\n", (void *)0);
	ft_printf("ft_printf 'd' : %d\n", INT_MIN);
	printf("printf 'd' :    %d\n\n", INT_MIN);
	ft_printf("ft_printf 'i' : %i\n", INT_MIN);
	printf("printf 'i' :    %i\n\n", INT_MIN);
	ft_printf("ft_printf 'u' : %u\n", UINT_MAX);
	printf("printf 'u' :    %u\n\n", UINT_MAX);
	ft_printf("ft_printf 'x' : %x\n", UINT_MAX, 'x');
	printf("printf : 'x'    %x\n\n", UINT_MAX);
	ft_printf("ft_printf 'X' : %X\n", UINT_MAX, 'X');
	printf("printf : 'X'    %X\n\n", UINT_MAX);
	ft_printf("ft_printf percent : 100%%\n");
	printf("printf percent :    100%%\n\n");
	return (0);
}
*/

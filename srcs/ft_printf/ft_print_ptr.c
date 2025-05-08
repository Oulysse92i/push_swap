/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:18:37 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/09 10:56:12 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str);
int	ft_putchar(char c);

int	print_hex_long(unsigned long n)
{
	char	*base;
	int		count;

	base = 0;
	count = 0;
	base = "0123456789abcdef";
	if (n > 15)
		count += print_hex_long((n / 16));
	count += ft_putchar(base[n % 16]);
	return (count);
}

int	print_ptr(unsigned long n)
{
	int	count;

	count = 0;
	if (!n)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	if (n == 0)
		count += ft_putchar('0');
	else
		count += print_hex_long(n);
	return (count);
}

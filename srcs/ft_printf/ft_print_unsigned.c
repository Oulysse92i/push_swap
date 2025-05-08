/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:49:30 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/09 10:56:11 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c);
int	ft_putstr(char *str);

int	ft_putnbr(int n)
{
	int	count;
	int	rest;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	rest = (n % 10) + '0';
	count += ft_putchar(rest);
	return (count);
}

int	ft_putunbr(unsigned int n)
{
	int	count;
	int	rest;

	count = 0;
	if (n >= 10)
		count += ft_putnbr(n / 10);
	rest = (n % 10) + '0';
	count += ft_putchar(rest);
	return (count);
}

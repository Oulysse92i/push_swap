/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:45:51 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/09 10:56:13 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int n, char format)
{
	char	*base;
	int		count;

	base = 0;
	count = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else if (format == 'x')
		base = "0123456789abcdef";
	if (n > 15)
		count += print_hex((n / 16), format);
	count += ft_putchar(base[n % 16]);
	return (count);
}

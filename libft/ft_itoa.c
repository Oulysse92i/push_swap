/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:18:18 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/21 13:12:16 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);

static int	get_size(int n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (size + 1);
	if (n < 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	if (size == 0)
		size++;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	long	nbr;
	int		i;

	size = get_size(n);
	i = 0;
	str = (char *)ft_calloc((size + 1), sizeof(char));
	if (str == NULL)
		return (str);
	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
		i++;
	}
	str[size] = '\0';
	while (size > i)
	{
		size--;
		str[size] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (str);
}
/*
#include <stdio.h>
#include <limits.h>
int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	printf("%s\n", ft_itoa(0));
	return (0);
}
*/

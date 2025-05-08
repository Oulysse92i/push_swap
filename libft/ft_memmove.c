/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:58 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/21 12:05:15 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	s = (char *)src;
	d = (char *)dest;
	i = 0;
	if (!d && !s)
		return (NULL);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	char		*res;
	char 	*s1;
	char 	*s2;
	int		n;
	size_t	size;

	s1 = av[1];
	s2 = av[2];
	n = atoi(&av[3][0]);
	size = n;
	res = (char *)ft_memmove(s1, s2, size);
	printf("ft_memmove : %s\n", (res));
	printf("   memmove : %s\n", (char *)memmove(s1, s2, size));
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:06:10 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/22 17:49:44 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
		n--;
	}
	return (0);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	int		res;
	char 	*s1;
	char 	*s2;
	int		n;
	size_t	size;

	s1 = av[1];
	s2 = av[2];
	n = atoi(&av[3][0]);
	size = n;
	res = ft_memcmp(s1, s2, n);
	printf("%d\n", (res));
	return (0);
}
*/
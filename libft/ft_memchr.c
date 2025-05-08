/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:54:26 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/22 17:45:13 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tab;
	unsigned char	charset;
	size_t			i;

	tab = (unsigned char *)s;
	i = 0;
	charset = c;
	while (i < n)
	{
		if (tab[i] == charset)
			return (tab + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	char	*found;
	char 	*str;
	char 	search;
	int		n;
	size_t	size;

	str = av[1];
	search = av[2][0];
	n = atoi(&av[3][0]);
	size = n;
	found = (char *)ft_memchr(str, search, size);
	found++;
	printf("%s\n", (found));
	return (0);
}
*/

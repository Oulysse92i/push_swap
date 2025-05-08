/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:36 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/20 18:39:48 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
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
	res = (char *)ft_memcpy(s1, s2, size);
	printf("ft_memcpy : %s\n", (res));
	printf("   memcpy : %s\n", (char *)memcpy(s1, s2, size));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:44:16 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/20 18:44:27 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (src[j] != '\0' && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (size > 0)
		dest[j] = '\0';
	return (i);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>

int	ft_atoi(const char *str);

int main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	printf("ft_strlcpy : %zu\n", ft_strlcpy(av[1], av[2], atoi(av[3])));
	printf("   strlcpy : %zu\n", strlcpy(av[1], av[2], atoi(av[3])));
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:50:44 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/20 18:43:40 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = 0;
	s_len = 0;
	while (dest[d_len] != '\0')
		d_len++;
	while (src[s_len] != '\0')
		s_len++;
	i = 0;
	j = d_len;
	if (size == 0 || size <= d_len)
		return (s_len + size);
	while (src[i] != '\0' && i < size - d_len - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (d_len + s_len);
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
	printf("ft_strlcat : %zu\n", ft_strlcat(av[1], av[2], atoi(av[3])));
	printf("   strlcat : %zu\n", strlcat(av[1], av[2], atoi(av[3])));
	return (0);
}
*/
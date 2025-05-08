/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:06:10 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/16 11:33:40 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	tab = malloc(nmemb * size);
	if (tab == NULL)
		return (tab);
	ft_bzero(tab, nmemb * size);
	return (tab);
}
/*
#include <stdio.h>

int	main (int ac, char **av)
{
	char	*tab;

	if (ac != 3)
		return (0);
	tab = ft_calloc(atoi(av[1]), atoi(av[2]));
	printf("%s\n", tab);
	return (0);
}
*/

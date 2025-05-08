/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:45:41 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/18 14:18:21 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	*s;

	s = av[1];
	if (ac != 3)
		return (0);
	ft_bzero(s, atoi(av[2]));
	printf("%s\n", s);
	return (0);
	
}
*/

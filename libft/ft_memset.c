/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:46:05 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/22 17:46:16 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	int	length;
	int	tab[] = {54, 85, 20, 63, 21};

	ft_memset(tab, 0, 20);
	length = 0;
	while(length < 5) 
	{
        printf( "%d\n", tab[length]);
		length++;
    }
    return 0;
}
*/

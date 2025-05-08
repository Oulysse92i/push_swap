/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:09:04 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/21 13:46:35 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	printf("ft_tolower : %d\n", ft_tolower(atoi(av[1])));
	printf("   tolower : %d\n", ft_tolower(atoi(av[1])));
	return (0);
}
*/
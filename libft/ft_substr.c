/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:24:32 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/26 10:12:55 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*tab;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if ((start + len) > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (start > ft_strlen(s))
		len = 0;
	tab = ft_calloc(len + 1, sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		if (j < len && i >= start)
		{
			tab[j] = s[i];
			j++;
		}
		i++;
	}
	tab[j] = '\0';
	return ((char *)tab);
}
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *test;
	test = ft_substr("hola", 0, 18446744073709551615);
	printf("%s\n", test);
	free (test);
	return (0);
}
*/
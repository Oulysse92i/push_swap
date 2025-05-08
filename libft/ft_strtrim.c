/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:01:01 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/21 13:43:10 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(const char *s);

static int	is_charset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_tab_size(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (is_charset(s1[i], set) == 1 && s1[i])
	{
		i++;
	}
	j = i;
	while (s1[j])
		j++;
	j--;
	while (is_charset(s1[j], set) == 1 && j >= i)
	{
		j--;
	}
	return (j - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		k;
	int		i;
	int		size;
	char	*tab;

	i = 0;
	size = ft_tab_size(s1, set);
	if (!s1 || !set)
		return (NULL);
	while (is_charset(s1[i], set) == 1)
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	tab = malloc(sizeof(char) * (size + 1));
	if (tab == NULL)
		return (tab);
	ft_bzero(tab, size);
	k = 0;
	while (k < size)
	{
		tab[k++] = s1[i++];
	}
	tab[k] = '\0';
	return (tab);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char *s1 =  ft_strtrim("x", "x");
	printf("%s\n", s1);
	printf("%d\n", strcmp(s1, ""));
	return (0);
}
*/

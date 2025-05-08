/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:55:25 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/20 17:25:02 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	if (s == NULL)
		return (0);
	while ((s[i] == c) && (s[i]))
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i] != '\0')
		{
			while (s[i] == c)
				i++;
			if (s[i] != '\0')
				count++;
		}
		else
			i++;
	}
	return (count);
}

static char	*word_len(char const *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[i++] = s[start++];
	}
	word[i] = '\0';
	return (word);
}

void	ft_free_all(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
}

char	**ft_create_tab(char const *s, char **tab, unsigned int i, char c)
{
	int					j;
	int					k;
	int					nb_words;

	k = 0;
	nb_words = count_words(s, c);
	while (k < nb_words)
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		j = i;
		while (s[j] != c && s[j])
			j++;
		tab[k] = word_len(s, i, j);
		if (tab[k] == NULL)
		{
			ft_free_all(tab, k);
			return (NULL);
		}
		k++;
		i = j;
	}
	tab[k] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	unsigned int		i;
	int					nb_words;
	char				**tab;

	i = 0;
	nb_words = count_words(s, c);
	tab = malloc((nb_words + 1) * sizeof(char *));
	if (tab == NULL)
	{
		free(tab);
		return (NULL);
	}
	if (ft_create_tab(s, tab, i, c) == NULL)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
/*
ft_free_all(ft_create_tab(s, tab, i, c), nb_words);
#include <stdio.h>

int	main(int ac, char **av)
{
	char	**tab;
	int		i;

	(void)ac;
	(void)av;
	i = 0;;
	tab = ft_split("hello!", ' ');
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
*/

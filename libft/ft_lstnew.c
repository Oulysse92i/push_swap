/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:42:49 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/21 12:23:53 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (elem == NULL)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node = ft_lstnew("Hello world!");

	printf("Content : %s\n", (char *)node->content);
	printf("Next : %p\n", (void *)node->next);
	return (0);
}
*/

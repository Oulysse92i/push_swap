/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:02:40 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/22 18:58:02 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	elem = ft_lstlast(*lst);
	elem->next = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*back = ft_lstnew("node1");

	ft_lstadd_back(&back, ft_lstnew("node2"));
	ft_lstadd_back(&back, ft_lstnew("node3"));

	while (back)
	{
		printf("%s\n", (char *)back->content);
		back = back->next;
	}
	while (back)
	{
		t_list *tmp = back;
		back = back->next;
		free(tmp);
	}
	return (0);
}
*/
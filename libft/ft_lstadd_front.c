/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:14:22 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/10 17:04:50 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*front = ft_lstnew("Node1");

	ft_lstadd_front(&front, ft_lstnew("Node2"));
	ft_lstadd_front(&front, ft_lstnew("Node3"));
	ft_lstadd_front(&front, ft_lstnew("Node4"));
	ft_lstadd_front(&front, ft_lstnew("Node5"));
	ft_lstadd_front(&front, ft_lstnew("Node6"));

	while (front)
	{
		printf("%s\n", (char *)front->content);
		front = front->next;
	}
	while (front)
	{
		t_list *tmp = front;
		front = front->next;
		free(tmp);
	}
	return (0);
}
*/

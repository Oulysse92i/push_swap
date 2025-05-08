/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:44:17 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/28 16:11:54 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*elem;

	elem = lst;
	if (elem == NULL)
		return (NULL);
	while (elem->next != NULL)
	{
		elem = elem->next;
	}
	return (elem);
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*lst = ft_lstnew("node1");
	ft_lstadd_front(&lst, ft_lstnew("node2"));
	ft_lstadd_front(&lst, ft_lstnew("node3"));

	t_list	*last = ft_lstlast(lst);
	printf("List node : : %s\n", (char *)last->content);
	while (lst)
	{
		t_list *tmp = lst;
		lst = lst->next;
		free(tmp);
	}
	return (0);
}
*/

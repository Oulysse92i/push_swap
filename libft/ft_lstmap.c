/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:48:44 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/21 13:06:56 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*new_lst;
	void	*bis;

	new_lst = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	while (lst)
	{
		bis = (*f)(lst->content);
		dest = ft_lstnew(bis);
		if (dest == NULL)
		{
			del(bis);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, dest);
		lst = lst->next;
	}
	return (new_lst);
}
/*
#include <stdio.h>

void	del_content(void *content)
{
	free(content);
}

void	*print_content(void *content)
{
	printf("%s\n", (char *)content);
	return (0);
}

int	main(void)
{
	t_list	*back = ft_lstnew("node1");

	ft_lstadd_back(&back, ft_lstnew("node2"));
	ft_lstadd_back(&back, ft_lstnew("node3"));

	t_list *lst = ft_lstmap(back, print_content, del_content);

	printf("List : %p\n", (void *)lst->content);
	while (back)
	{
		t_list *tmp = back;
		back = back->next;
		free(tmp);
	}
	while (lst)
	{
		t_list *tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
	return (0);
}
*/

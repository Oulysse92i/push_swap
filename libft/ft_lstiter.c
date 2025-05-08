/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:10:35 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/21 12:58:59 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
#include <stdio.h>
void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*back = ft_lstnew("node1");

	ft_lstadd_back(&back, ft_lstnew("node2"));
	ft_lstadd_back(&back, ft_lstnew("node3"));

	ft_lstiter(back, print_content);
	while (back)
	{
		t_list *tmp = back;
		back = back->next;
		free(tmp);
	}
	return (0);
}
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:36:10 by ugaudich          #+#    #+#             */
/*   Updated: 2025/04/18 18:36:11 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	index_stack(t_stack *stack)
{
	int		i;
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	while (tmp1)
	{
		i = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp2->data < tmp1->data)
				i++;
			tmp2 = tmp2->next;
		}
		tmp1->index = i;
		tmp1 = tmp1->next;
	}
}

void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size)
{
	int		i;
	int		size;
	t_stack	*tmp;

	i = 0;
	size = ft_ps_lstsize(*stack_a);
	while (i < size)
	{
		tmp = *stack_a;
		if (tmp->index <= i)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
			i++;
		}
		else if (tmp->index <= i + chunk_size)
		{
			pb(stack_b, stack_a);
			i++;
		}
		else
			ra(stack_a);
	}
}

void	move_max_to_top_b(t_stack **stack_b)
{
	int		max;
	int		pos;
	int		mid;
	t_stack	*tmp;

	max = ft_ps_lstsize(*stack_b) - 1;
	tmp = *stack_b;
	pos = 0;
	while (tmp && tmp->index != max)
	{
		tmp = tmp->next;
		pos++;
	}
	mid = ft_ps_lstsize(*stack_b) / 2;
	if (pos <= mid)
	{
		while ((*stack_b)->index != max)
			rb(stack_b);
	}
	else
	{
		while ((*stack_b)->index != max)
			rrb(stack_b);
	}
}

void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b)
	{
		move_max_to_top_b(stack_b);
		pa(stack_a, stack_b);
	}
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk_size;

	chunk_size = 23;
	push_chunks_to_b(stack_a, stack_b, chunk_size);
	sort_b_to_a(stack_a, stack_b);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:17:05 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/18 16:54:48 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack_a)
{
	int	min;

	if (!stack_a)
		return (0);
	min = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data < min)
			min = stack_a->data;
		stack_a = stack_a->next;
	}
	return (min);
}

int	find_max(t_stack *stack_a)
{
	int	max;

	if (!stack_a)
		return (0);
	max = stack_a->data;
	while (stack_a)
	{
		if (stack_a->data > max)
			max = stack_a->data;
		stack_a = stack_a->next;
	}
	return (max);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		i;
	int		size;
	t_stack	*tmp;

	min = find_min(*stack_a);
	tmp = *stack_a;
	i = 0;
	while (tmp && tmp->data != min)
	{
		tmp = tmp->next;
		i++;
	}
	size = ft_ps_lstsize(*stack_a);
	if (i <= size / 2)
	{
		while ((*stack_a)->data != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->data != min)
			rra(stack_a);
	}
	pb(stack_b, stack_a);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_ps_lstsize(*stack_a);
	while (size-- > 3)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (ft_ps_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}
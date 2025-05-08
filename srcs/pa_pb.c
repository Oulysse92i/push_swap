/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:44:44 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/18 17:03:06 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*top;

	if (!stack_from || !*stack_from)
		return ;
	top = *stack_from;
	*stack_from = top->next;
	if (*stack_from)
		(*stack_from)->prev = NULL;
	top->next = *stack_to;
	if (*stack_to)
		(*stack_to)->prev = top;
	*stack_to = top;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
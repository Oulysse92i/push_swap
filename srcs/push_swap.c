/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:01:48 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/10 16:06:19 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**parse_single_arg(char *av, int *is_single)
{
	char	**args;

	args = ft_split(av, ' ');
	if (!args || !args[0])
	{
		if (args)
			free_tab(args);
		return (NULL);
	}
	*is_single = 1;
	return (args);
}

int	process_args(t_stack **stack_a, int ac, char **av, int *is_single)
{
	char	**args;

	*is_single = 0;
	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		args = parse_single_arg(av[1], is_single);
		if (!args)
			return (0);
	}
	else
		args = av + 1;
	if (!input_check(stack_a, args))
	{
		if (*is_single)
			free_tab(args);
		free_stack(stack_a);
		return (0);
	}
	if (*is_single)
		free_tab(args);
	return (1);
}

void	execute_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_ps_lstsize(*stack_a);
	if (size == 2 && (*stack_a)->data > (*stack_a)->next->data)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		is_single;

	stack_a = NULL;
	stack_b = NULL;
	if (!process_args(&stack_a, ac, av, &is_single))
	{
		if (ac > 1)
			error_exit("Error\n");
		return (0);
	}
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	index_stack(stack_a);
	execute_sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
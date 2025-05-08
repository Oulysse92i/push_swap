/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:05:58 by ugaudich          #+#    #+#             */
/*   Updated: 2024/12/19 14:34:43 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../srcs/ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				nb_op;
	int				index;
	int				median;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	push(t_stack **stack_from, t_stack **stack_to);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

void	swap(t_stack **stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	rev_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

int		check_double(char **av);
int		check_nb(char **av);
int		input_check(t_stack **stack_a, char **av);

void	add_node(t_stack **stack, int nb);

char	**parse_single_arg(char *av, int *is_single);
int		process_args(t_stack **stack_a, int ac, char **av, int *is_single);
void	execute_sort(t_stack **stack_a, t_stack **stack_b);

void	index_stack(t_stack *stack);
void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b, int chunk_size);
void	move_max_to_top_b(t_stack **stack_b);
void	sort_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	sort_big(t_stack **stack_a, t_stack **stack_b);

int		find_min(t_stack *stack_a);
int		find_max(t_stack *stack_a);
void	sort_three(t_stack **stack_a);
void	push_min_to_b(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

void	error_exit(char *str);
int		ft_ps_lstsize(t_stack *lst);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack **stack);
void	free_tab(char **tab);

#endif
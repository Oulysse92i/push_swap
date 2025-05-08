/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 11:03:07 by ugaudich          #+#    #+#             */
/*   Updated: 2025/03/12 11:03:08 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_double(char **av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (av[len])
		len++;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_nb(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atol(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	input_check(t_stack **stack_a, char **av)
{
	long	tmp;
	int		i;

	if (!av || !av[0])
		return (0);
	if (!check_nb(av))
		return (0);
	if (!check_double(av))
		return (0);
	i = 0;
	while (av[i])
	{
		tmp = ft_atol(av[i]);
		if (tmp < INT_MIN || tmp > INT_MAX)
			return (0);
		add_node(stack_a, (int)tmp);
		i++;
	}
	return (1);
}
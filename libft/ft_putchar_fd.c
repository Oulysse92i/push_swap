/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugaudich <ugaudich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:47:32 by ugaudich          #+#    #+#             */
/*   Updated: 2024/11/14 15:21:16 by ugaudich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <fcntl.h>

int	main(int ac, char **av)
{
	int file;
	(void)ac;
	file = open(av[2], O_WRONLY);
	ft_putchar_fd(av[1][0], file);
	close (file);
	return (0);
}
*/

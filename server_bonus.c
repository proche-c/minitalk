/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int i, int fd)
{
	long	nbr;

	nbr = i;
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd('0' + nbr % 10, fd);
	}
	else
		ft_putchar_fd('0' + nbr % 10, fd);
}

void	ft_action(int sig)
{
	static int	counter = 0;
	static char	c = 0;

	if (sig == SIGUSR2)
		c = c | 128 >> counter;
	counter++;
	if (counter == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
		{
			write(1, &c, 1);
			c = 0;
			counter = 0;
		}
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	while (1)
		sleep(5);
	return (0);
}

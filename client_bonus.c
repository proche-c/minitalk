/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:04:07 by proche-c          #+#    #+#             */
/*   Updated: 2022/01/18 17:30:55 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi_mod(const char *str)
{
	int	i;
	int	num;
	int	result;

	i = 0;
	result = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		num = str[i] - 48;
		result = result * 10 + num;
		i++;
	}
	return (result);
}

void	ft_kill(int pid, char *msg)
{
	int	i;
	int	j;

	j = 0;
	while (msg[j] != '\0')
	{
		i = 7;
		while (i > -1)
		{
			if (msg[j] >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			i--;
			usleep(100);
		}
		j++;
	}
}

int	main(int ac, char **arg)
{
	int	pid;

	if (ac != 3)
		write(1, "Error\n", 6);
	pid = ft_atoi_mod(arg[1]);
	ft_kill(pid, arg[2]);
	return (0);
}

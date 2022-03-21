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

void 	ft_kill(int pid, char *msg)
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
			{
				kill(pid, SIGUSR2);
				ft_putstr_fd("1\n", 1);
			}
			else
			{
				kill(pid, SIGUSR1);
				ft_putstr_fd("0\n", 1);
			}
			i--;
		}
		j++;
	}
}

int	main(int ac, char **arg)
{
	int	pid;

	if (ac != 3)
		ft_putstr_fd("Error\n", 1);
	pid = ft_atoi(arg[1]);
	ft_kill(pid, arg[2]);
	
	while(1)
		pause();
	return(0);	
}

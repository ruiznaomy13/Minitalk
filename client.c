/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:51:01 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/30 01:18:23 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "needs/printf/inc/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <limits.h>

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = ((num * 10) + (str[i] - '0'));
		i++;
	}
	return ((int)(num));
}

void	str_bit(char *msj, int pid)
{
	int	i;
	int	c;
	int	bit;

	i = -1;
	while (msj[++i])
	{
		c = msj[i];
		bit = 0;
		while (bit < 8)
		{
			if ((c & (0x01 << bit)) != 0)
			{
				kill(pid, SIGUSR1);
				usleep(50);
			}
			else
			{
				kill(pid, SIGUSR2);
				usleep(50);
			}
			usleep(100);
			bit++;
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = ft_atoi(av[1]);
	if (ac == 3)
		str_bit(av[2], pid);
	else
		write(1, "Los argumentos no son correctos\n", 32);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:52:07 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/30 12:58:51 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "needs/printf/inc/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <limits.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_gestion(int signal)
{
	static int	oct = 0;
	static int	c = '\0';

	if (signal == SIGUSR1)
		c |= (0x01 << oct);
	oct++;
	if (oct == 8)
	{
		ft_putchar(c);
		oct = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("PID = %i\n", pid);
	while (50)
	{
		signal(SIGUSR1, ft_gestion);
		signal(SIGUSR2, ft_gestion);
		sleep(50);
	}
	return (0);
}

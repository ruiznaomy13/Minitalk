/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:58:51 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/13 13:08:49 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	ft_put_nums(long int num, int ln)
{
	if (num < 0)
	{
		if (ft_put_char('-') == -1)
			return (-1);
		num *= -1;
		ln++;
	}
	if (num > 9)
	{
		ln = ft_put_nums(num / 10, ln);
		if (ln == -1)
			return (-1);
	}
	if (ft_put_char((num % 10) + '0') == -1)
		return (-1);
	ln++;
	return (ln);
}

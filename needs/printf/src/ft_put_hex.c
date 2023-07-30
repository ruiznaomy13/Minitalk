/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 12:30:55 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/13 13:08:46 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	ft_put_hex(unsigned int num, char type, int ln)
{
	char	*hex_val;

	if (type == 'X')
		hex_val = "0123456789ABCDEF";
	else
		hex_val = "0123456789abcdef";
	if (num > 15)
	{
		ln = ft_put_hex(num / 16, type, ln);
		if (ln == -1)
			return (-1);
	}
	if (ft_put_char(hex_val[num % 16]) == -1)
		return (-1);
	ln++;
	return (ln);
}

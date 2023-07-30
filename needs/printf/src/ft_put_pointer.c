/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:18:25 by ncastell          #+#    #+#             */
/*   Updated: 2023/07/13 13:08:52 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

int	ft_put_pointer(unsigned long num, int ln)
{
	char	*pointer_val;

	pointer_val = "0123456789abcdef";
	if (num > 15)
	{
		ln = ft_put_pointer(num / 16, ln);
		if (ln == -1)
			return (-1);
	}
	if (ft_put_char(pointer_val[num % 16]) == -1)
		return (-1);
	ln++;
	return (ln);
}

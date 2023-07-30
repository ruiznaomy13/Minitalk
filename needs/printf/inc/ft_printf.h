/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncastell <ncastell@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:53:12 by ncastell          #+#    #+#             */
/*   Updated: 2023/03/23 13:27:02 by ncastell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_put_char(int c);
int		ft_put_str(char *str);
int		ft_put_nums(long int num, int ln);
int		ft_put_hex(unsigned int num, char type, int ln);
int		ft_put_pointer(unsigned long num, int ln);

#endif
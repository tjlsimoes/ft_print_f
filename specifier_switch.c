/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_switch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:42:16 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 13:02:11 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier_switch(char c, va_list args, int count)
{
	if (c == 'c')
		count = putchar_fd_count(va_arg(args, int), 1, count);
	else if (c == 's')
		count = putstr_fd_count(va_arg(args, char *), 1, count);
	else if (c == 'd' || c == 'i')
		count = putnbr_fd_count(va_arg(args, int), 1, count);
	else if (c == 'u')
		count = putunint_fd_count(va_arg(args, unsigned int), 1, count);
	else if (c == '%')
		count = putstr_fd_count("%", 1, count);
	else if (c == 'x')
		count = putbase_fd_count(va_arg(args, unsigned int),
				1, "0123456789abcdef", count);
	else if (c == 'X')
		count = putbase_fd_count(va_arg(args, unsigned int),
				1, "0123456789ABCDEF", count);
	return (count);
}

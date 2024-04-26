/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer_fd_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:38:52 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/26 10:58:02 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpointer_fd_count(unsigned long nbr, int fd, int count)
{
	if (nbr == 0)
	{
		write(fd, "(nil)", 5);
		count += 5;
		return (count);
	}
	write(fd, "0x", 2);
	count += 2;
	count = putbase_fd_count(nbr, 1, "0123456789abcdef", count);
	return (count);
}

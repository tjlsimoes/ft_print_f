/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putbase_fd_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:41:51 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/05/21 16:04:31 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putbase_fd_count(unsigned long nbr, int fd, char *base, int count)
{
	if (nbr >= 16)
	{
		count = putbase_fd_count((nbr / 16), 1, base, count);
		count = putbase_fd_count((nbr % 16), 1, base, count);
	}
	else
	{
		write(fd, &base[nbr], 1);
		count++;
	}
	return (count);
}

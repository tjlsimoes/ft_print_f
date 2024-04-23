/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpointer_fd_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 14:38:52 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 16:16:27 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putpointer_fd_count(int nbr, int fd, int count)
{
	char	*s;
	char	*base_to;

	base_to = "0123456789abcdef";
	if (nbr == 0)
	{
		write(fd, "(nil)", 5);
		count += 5;
		return (count);
	}
	write(fd, "0x", 2);
	count += 2;
	s = convert_base(nbr, base_to);
	count = putstrrev_fd_count(s, fd, count);
	free(s);
	return (count);
}

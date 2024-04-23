/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjorge-l <tjorge-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:35:06 by tjorge-l          #+#    #+#             */
/*   Updated: 2024/04/23 12:35:17 by tjorge-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr_fd_count(int n, int fd, int count)
{
	char		c;
	int			nbr_digits;
	long		n_ll;

	n_ll = (long)n;
	if (n_ll < 0)
	{
		n_ll *= -1;
		count++;
		write(fd, "-", 1);
	}
	nbr_digits = get_nbr_digits(n_ll);
	while (nbr_digits > 0)
	{
		c = (n_ll / power(10, nbr_digits - 1)) + 48;
		write(fd, &c, 1);
		count++;
		n_ll = n_ll % power(10, nbr_digits - 1);
		nbr_digits--;
	}
	return (count);
}
